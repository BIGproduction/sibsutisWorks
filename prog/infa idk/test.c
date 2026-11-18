#include <stdio.h>

#define CPU_STATE_SIZE 8
#define MEMORY_SIZE 256

int init_memory(int *memory);
void print_info(int op_code, int *cpu_state, int operand_addr);
int check_repeated_interrupt(int *cpu_state);

/*
cpu_state[0] - счетчик команд (pc)
cpu_state[1] - аккумулятор (acc), хранит текущий результат
cpu_state[2] - регистр команд (ir), хранит текущий опкод
cpu_state[3] - вектор прерываний (адрес обработчика ошибок)
cpu_state[4] - флаг остановки (0 = работает, 1 = остановлен)
cpu_state[5] - код последней ошибки (0 = нет ошибки)
cpu_state[6] - проверка обработчика прерываний
cpu_state[7] - резерв для будущих расширений
*/

int main(void) {
    int cpu_state[CPU_STATE_SIZE] = {0};
    int memory[MEMORY_SIZE] = {0};

    int status = init_memory(memory);
    if (status != 0) {
        return status;
    }

    int operand_addr = 0;
    int err = 0;

    cpu_state[0] = 4;         
    cpu_state[3] = memory[0]; 

    printf("--- начало работы процессора ---\n");

    while (cpu_state[4] == 0) {
        if (cpu_state[0] < 0 || cpu_state[0] >= MEMORY_SIZE) {
            err = check_repeated_interrupt(cpu_state);
            if (err) return 0;

            printf("pc = %d, command = %d, ERROR: out of bounds\n", cpu_state[0], cpu_state[2]);
            cpu_state[5] = 1;            
            cpu_state[0] = cpu_state[3]; 
            cpu_state[6] = 1;
            continue;
        }

        cpu_state[2] = memory[cpu_state[0]];
        
        if (cpu_state[2] != 0) {
            if (cpu_state[0] + 1 >= MEMORY_SIZE) {
                err = check_repeated_interrupt(cpu_state);
                if (err) return 0;

                printf("pc = %d, command = %d, ERROR: out of bounds\n", cpu_state[0], cpu_state[2]);
                cpu_state[5] = 1;
                cpu_state[0] = cpu_state[3];
                cpu_state[6] = 1;
                continue;
            }
            operand_addr = memory[cpu_state[0] + 1]; 
        }

        if (cpu_state[2] != 0 && (operand_addr < 0 || operand_addr >= MEMORY_SIZE)) {
            err = check_repeated_interrupt(cpu_state);
            if (err) return 0;

            printf("pc = %d, command = %d, ERROR: out of bounds\n", cpu_state[0], cpu_state[2]);
            cpu_state[5] = 1;
            cpu_state[0] = cpu_state[3];
            cpu_state[6] = 1;
            continue;
        }
        switch (cpu_state[2]) {

        case 0: // STOP
            operand_addr = 0;
            cpu_state[4] = 1;
            printf("STOP (0)\n");
            break;
            
        case 1: // LOAD
            cpu_state[1] = memory[operand_addr];
            printf("команда: LOAD (1) | операнд: %d | аккумулятор: %d\n", operand_addr, cpu_state[1]);
            cpu_state[0] += 2;
            break;

        case 2: // ADD
            cpu_state[1] += memory[operand_addr];
            printf("Команда: ADD (2)  | операнд: %d | аккумулятор: %d\n", operand_addr, cpu_state[1]);
            cpu_state[0] += 2;
            break;

        case 3: // SUB
            cpu_state[1] -= memory[operand_addr];
            printf("команда: SUB (3)  | операнд: %d | аккумулятор: %d\n", operand_addr, cpu_state[1]);
            cpu_state[0] += 2;
            break;

        case 4: // JUMP
            printf("команда: JUMP (4) | переход на адрес: %d\n", operand_addr);
            cpu_state[0] = operand_addr;
            break;

        case 5: // JUMP IF ZERO
            if (cpu_state[1] == 0) {
                printf("команда: JZ (5)   | ACC=0   | переход на адрес: %d\n", operand_addr);
                cpu_state[0] = operand_addr;
            } else {
                printf("команда: JZ (5)   | ACC!=0  | переход отменен, идем дальше\n");
                cpu_state[0] += 2;
            }
            break;

        default:
            err = check_repeated_interrupt(cpu_state);
            if (err) return 0;

            printf("pc = %d, command = %d, ERROR: unknown opcode\n", cpu_state[0], cpu_state[2]);
            cpu_state[0] = cpu_state[3]; 
            cpu_state[5] = 2;            
            cpu_state[6] = 1;
            continue;
        }
    }

    if (cpu_state[5] != 0) {
        printf("\n--- произошло прерывание ---\n");
        printf("код ошибки: %d\n", cpu_state[5]);
        if (cpu_state[3] != 0) {
            printf("переход по вектору прерываний на адрес: %d\n", cpu_state[3]);
        }
    } else {
        printf("\n--- программа успешно завершена ---\n");
    }

    return 0;
}

int init_memory(int *memory) {
    int i = 0;
    while (i < MEMORY_SIZE && scanf("%d", &memory[i]) == 1)
        i++;
    return 0;
}

int check_repeated_interrupt(int *cpu_state) {
    if (cpu_state == NULL) {
        return 1;
    }

    if (cpu_state[6] == 1) {
        printf("ERROR: repeated interruption\n");
        cpu_state[4] = 1;
        return 1;
    }
    return 0;
}