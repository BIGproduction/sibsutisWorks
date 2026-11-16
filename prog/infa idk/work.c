/*
 * Данная программа отражает ключевые принципы архитектуры фон Неймана
 * единое хранилище для данных  и команд (массив memory), последовательное выполнение,
 * наличие счетчика команд (cpu_state[0] - pc), АЛУ и регистров.
 */

#include <stdio.h>
#define CPU_STATE_SIZE 8
#define MEMORY_SIZE 256

int init_memory(int *memory);
void print_info(int op_code, int *cpu_state, int operand_addr);
int check_repeated_interrupt(int *cpu_state);

int main(void)
{
    /*
     * cpu_state[0] - счетчик команд (pc)
     * cpu_state[1] - аккумулятор (acc), хранит текущий результат
     * cpu_state[2] - регистр команд (ir), хранит текущий опкод
     * cpu_state[3] - вектор прерываний (адрес обработчика ошибок)
     * cpu_state[4] - флаг остановки (0 = работает, 1 = остановлен)
     * cpu_state[5] - код последней ошибки (0 = нет ошибки)
     * cpu_state[6] - проверка обработчика прерываний
     * cpu_state[7] - резерв для будущих расширений
     */
    int cpu_state[CPU_STATE_SIZE] = {0};

    int memory[MEMORY_SIZE] = {0};

    int status = init_memory(memory);
    if (status != 0)
    {
        return status;
    }

    int operand_addr, err;

    operand_addr = 0;
    err = 0;

    cpu_state[0] = 4;         // адрес первой команды
    cpu_state[3] = memory[0]; // вектор прерываний

    while (cpu_state[4] == 0)
    {
        if (cpu_state[0] < 0 || cpu_state[0] >= MEMORY_SIZE)
        {
            err = check_repeated_interrupt(cpu_state);
            if (err)
                return 0;

            printf("pc = %d, command = %d, ERROR: out of bounds\n", cpu_state[0], cpu_state[2]);
            cpu_state[5] = 1;            // код ошибки
            cpu_state[0] = cpu_state[3]; // переход на вектор прерываний
            cpu_state[6] = 1;
            continue;
        }

        cpu_state[2] = memory[cpu_state[0]]; // текущая команда
        if (cpu_state[2] != 0)
        {
            if (cpu_state[0] + 1 >= MEMORY_SIZE)
            {
                err = check_repeated_interrupt(cpu_state);
                if (err)
                    return 0;

                printf("pc = %d, command = %d, ERROR: out of bounds\n", cpu_state[0], cpu_state[2]);
                cpu_state[5] = 1;
                cpu_state[0] = cpu_state[3];
                cpu_state[6] = 1;
                continue;
            }
            operand_addr = memory[cpu_state[0] + 1]; // адрес операнда
        }

        if (cpu_state[2] != 0 && (operand_addr < 0 || operand_addr >= MEMORY_SIZE))
        {
            err = check_repeated_interrupt(cpu_state);
            if (err)
                return 0;

            printf("pc = %d, command = %d, ERROR: out of bounds\n", cpu_state[0], cpu_state[2]);
            cpu_state[5] = 1;
            cpu_state[0] = cpu_state[3];
            cpu_state[6] = 1;
            continue;
        }

        switch (cpu_state[2])
        {
        case 1: // LOAD
            cpu_state[1] = memory[operand_addr];
            print_info(1, cpu_state, operand_addr);
            cpu_state[0] += 2;
            break;

        case 2: // ADD
            cpu_state[1] += memory[operand_addr];
            print_info(2, cpu_state, operand_addr);
            cpu_state[0] += 2;
            break;

        case 3: // SUB
            cpu_state[1] -= memory[operand_addr];
            print_info(3, cpu_state, operand_addr);
            cpu_state[0] += 2;
            break;

        case 4: // JUMP
            print_info(4, cpu_state, operand_addr);
            cpu_state[0] = operand_addr;
            break;

        case 5: // JUMP IF ZERO
            print_info(5, cpu_state, operand_addr);
            if (cpu_state[1] == 0)
                cpu_state[0] = operand_addr;
            else
                cpu_state[0] += 2;
            break;

        case 0: // HALT
            operand_addr = 0;
            cpu_state[4] = 1;
            print_info(0, cpu_state, operand_addr);
            break;

        default:
            err = check_repeated_interrupt(cpu_state);
            if (err)
                return 0;

            printf("pc = %d, command = %d, ERROR: unknown opcode\n", cpu_state[0], cpu_state[2]);
            cpu_state[0] = cpu_state[3]; // переход на вектор прерываний
            cpu_state[5] = 2;            // код ошибки
            cpu_state[6] = 1;
            continue;
        }
    }

    return 0;
}

int init_memory(int *memory)
{
    int i = 0;
    while (i < MEMORY_SIZE && scanf("%d", &memory[i]) == 1)
        i++;

    return 0;
}

void print_info(int op_code, int *cpu_state, int operand_addr)
{
    switch (op_code)
    {
    case 1:
        printf("pc = %d, command = %d (LOAD), operand = %d, acc = %d\n", cpu_state[0], cpu_state[2], operand_addr, cpu_state[1]);
        break;

    case 2:
        printf("pc = %d, command = %d (ADD), operand = %d, acc = %d\n", cpu_state[0], cpu_state[2], operand_addr, cpu_state[1]);
        break;

    case 3:
        printf("pc = %d, command = %d (SUB), operand = %d, acc = %d\n", cpu_state[0], cpu_state[2], operand_addr, cpu_state[1]);
        break;

    case 4:
        printf("pc = %d, command = %d (JUMP), operand = %d\n", cpu_state[0], cpu_state[2], operand_addr);
        break;

    case 5:
        printf("pc = %d, command = %d (JUMP IF ZERO), operand = %d, acc = %d\n", cpu_state[0], cpu_state[2], operand_addr, cpu_state[1]);
        break;

    case 0:
        printf("pc = %d, command = %d (HALT). The program is completed\n", cpu_state[0], cpu_state[2]);
        break;

    default:
        break;
    }
}

int check_repeated_interrupt(int *cpu_state)
{
    if (cpu_state == NULL)
    {
        return 1;
    }

    if (cpu_state[6] == 1)
    {
        printf("ERROR: repeated interruption\n");
        cpu_state[4] = 1;
        return 1;
    }

    return 0;
}