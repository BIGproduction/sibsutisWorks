#include <stdio.h>

int main() {
    int cpu_state[8] = {0}; 
    int memory[256] = {0};

    FILE *file = fopen("program.txt", "r");
    if (file == NULL) {
        printf("не удалось открыть файл program.txt\n");
        return 1;
    }

    int i = 0;
    while (fscanf(file, "%d", &memory[i]) == 1 && i < 256) {
        i++;
    }
    fclose(file);

    cpu_state[3] = memory[0];
    cpu_state[4] = 0;
    
    printf("--- начало работы процессора ---\n");

    while (cpu_state[4] == 0 && cpu_state[5] == 0) {
        
        if (cpu_state[0] < 0 || cpu_state[0] >= 256) {
            cpu_state[5] = 2; 
            break;
        }

        cpu_state[2] = memory[cpu_state[0]]; 
        int opcode = cpu_state[2];
        int operand = 0;

        switch (opcode) {
            case 0: // STOP
                cpu_state[4] = 1; 
                printf("STOP (0)\n");
                break;

            case 1: // LOAD
                operand = memory[cpu_state[0] + 1]; 
                if (operand < 0 || operand >= 256) {
                    cpu_state[5] = 2; 
                    printf("выход за границы памяти (адрес %d)\n", operand);
                    break;
                }
                cpu_state[1] = memory[operand]; 
                printf("команда: LOAD (1) | операнд: %d | аккумулятор: %d\n", operand, cpu_state[1]);
                cpu_state[0] += 2; 
                break;

            case 2: // ADD
                operand = memory[cpu_state[0] + 1];
                if (operand < 0 || operand >= 256) {
                    cpu_state[5] = 2; 
                    printf("выход за границы памяти (адрес %d)\n", operand);
                    break;
                }
                cpu_state[1] += memory[operand]; 
                printf("Команда: ADD (2)  | операнд: %d | аккумулятор: %d\n", operand, cpu_state[1]);
                cpu_state[0] += 2;
                break;

            case 3: // SUB
                operand = memory[cpu_state[0] + 1];
                if (operand < 0 || operand >= 256) {
                    cpu_state[5] = 2; 
                    printf("выход за границы памяти (адрес %d)\n", operand);
                    break;
                }
                cpu_state[1] -= memory[operand]; 
                printf("команда: SUB (3)  | операнд: %d | аккумулятор: %d\n", operand, cpu_state[1]);
                cpu_state[0] += 2;
                break;

            case 4: // JUMP
                operand = memory[cpu_state[0] + 1]; 
                if (operand < 0 || operand >= 256) {
                    cpu_state[5] = 2; 
                    printf("переход за границы памяти (адрес %d)\n", operand);
                    break;
                }
                printf("команда: JUMP (4) | переход на адрес: %d\n", operand);
                cpu_state[0] = operand; 
                break;

            case 5: // JUMP IF ZERO
                operand = memory[cpu_state[0] + 1];
                
                if (operand < 0 || operand >= 256) {
                    cpu_state[5] = 2; 
                    printf("переход за границы памяти (адрес %d)\n", operand);
                    break;
                }
                
                if (cpu_state[1] == 0) {
                    printf("команда: JZ (5)   | ACC=0   | переход на адрес: %d\n", operand);
                    cpu_state[0] = operand; 
                } else {
                    printf("команда: JZ (5)   | ACC!=0  | переход отменен, идем дальше\n");
                    cpu_state[0] += 2; 
                }
                break;
            // --------------------------------------------

            default:
                cpu_state[5] = 1; 
                printf("неизвестная команда %d по адресу %d\n", opcode, cpu_state[0]);
                break;
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