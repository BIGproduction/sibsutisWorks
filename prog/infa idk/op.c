#include <stdio.h>
#include <stdlib.h>

int main() {
    int cpu_state[8] = {0}; 
    int memory[256] = {0};

    FILE *file = fopen("program.txt", "r");
    if (file == NULL) {
        printf("Ошибка: Не удалось открыть файл program.txt\n");
        return 1;
    }

    int i = 0;
    while (fscanf(file, "%d", &memory[i]) == 1 && i < 256) {
        i++;
    }
    fclose(file);

    cpu_state[3] = memory[0]; 
    cpu_state[4] = 0;         
    
    printf("--- Начало работы процессора ---\n");

    while (cpu_state[4] == 0 && cpu_state[5] == 0) {
        
        if (cpu_state[0] < 0 || cpu_state[0] >= 256) {
            cpu_state[5] = 2; 
            break;
        }

        cpu_state[2] = memory[cpu_state[0]]; 
        int opcode = cpu_state[2];
        int operand = 0;

        switch (opcode) {
            case 0: // СТОП
                cpu_state[4] = 1; 
                printf("STOP (0)\n");
                break;

            case 1: // LOAD
                operand = memory[cpu_state[0] + 1]; 
                if (operand < 0 || operand >= 256) {
                    cpu_state[5] = 2; 
                    printf("ОШИБКА: Выход за границы памяти (адрес %d)\n", operand);
                    break;
                }
                cpu_state[1] = memory[operand]; 
                printf("Команда: LOAD (1) | Операнд: %d | Аккумулятор: %d\n", operand, cpu_state[1]);
                cpu_state[0] += 2; 
                break;

            case 2: // ADD
                operand = memory[cpu_state[0] + 1];
                if (operand < 0 || operand >= 256) {
                    cpu_state[5] = 2; 
                    printf("ОШИБКА: Выход за границы памяти (адрес %d)\n", operand);
                    break;
                }
                cpu_state[1] += memory[operand]; 
                printf("Команда: ADD (2)  | Операнд: %d | Аккумулятор: %d\n", operand, cpu_state[1]);
                cpu_state[0] += 2;
                break;

            case 3: // SUB
                operand = memory[cpu_state[0] + 1];
                if (operand < 0 || operand >= 256) {
                    cpu_state[5] = 2; 
                    printf("ОШИБКА: Выход за границы памяти (адрес %d)\n", operand);
                    break;
                }
                cpu_state[1] -= memory[operand]; 
                printf("Команда: SUB (3)  | Операнд: %d | Аккумулятор: %d\n", operand, cpu_state[1]);
                cpu_state[0] += 2;
                break;

            case 4: // JUMP
                operand = memory[cpu_state[0] + 1]; 
                if (operand < 0 || operand >= 256) {
                    cpu_state[5] = 2; 
                    printf("ОШИБКА: Переход за границы памяти (адрес %d)\n", operand);
                    break;
                }
                printf("Команда: JUMP (4) | Переход на адрес: %d\n", operand);
                cpu_state[0] = operand; 
                break;

            case 5: // JUMP IF ZERO
                operand = memory[cpu_state[0] + 1]; 
                if (operand < 0 || operand >= 256) {
                    cpu_state[5] = 2; 
                    printf("ОШИБКА: Переход за границы памяти (адрес %d)\n", operand);
                    break;
                }
                
                if (cpu_state[1] == 0) {
                    printf("Команда: JZ (5)   | ACC=0   | Переход на адрес: %d\n", operand);
                    cpu_state[0] = operand; 
                } else {
                    printf("Команда: JZ (5)   | ACC!=0  | Переход отменен, идем дальше\n");
                    cpu_state[0] += 2; 
                }
                break;

            default:
                cpu_state[5] = 1; 
                printf("ОШИБКА: Неизвестная команда %d по адресу %d\n", opcode, cpu_state[0]);
                break;
        }
    }

    if (cpu_state[5] != 0) {
        printf("\n--- ПРОИЗОШЛО ПРЕРЫВАНИЕ ---\n");
        printf("Код ошибки: %d\n", cpu_state[5]);
        if (cpu_state[3] != 0) {
            printf("Переход по вектору прерываний на адрес: %d\n", cpu_state[3]);
        }
    } else {
        printf("\n--- Программа успешно завершена ---\n");
    }

    return 0;
}