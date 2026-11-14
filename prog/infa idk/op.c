#include <stdio.h>
#include <stdlib.h>

/*
cpu_state[0] - счетчик команд (pc)
cpu_state[1] - аккумулятор (acc), хранит текущий результат
cpu_state[2] - регистр команд (ir), хранит текущий опкод
cpu_state[3] - вектор прерываний (адрес обработчика ошибок)
cpu_state[4] - флаг остановки (0 = работает, 1 = остановлен)
cpu_state[5] - код последней ошибки (0 = нет ошибки)
cpu_state[6] - резерв для будущих расширений
cpu_state[7] - резерв для будущих расширений
*/

int main() {
    int cpu_state[8] = {0};
    int memory[256] = {0};

    FILE *file = fopen("program.txt", "r");
    if (file == NULL) {
        print("не удалось открть файл");
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
        
        cpu_state[2] == memory[cpu_state[0]];
        int opcode = cpu_state[2];
        int operand = 0;

        switch (opcode) {
            case 0: // остановка
                cpu_state[4] = 1; 
                printf("STOP (0)\n");
                break;

            case 1: // загрузка в аккумулятор
                operand = memory[cpu_state[0] + 1];
                if (operand < 0 || operand >= 256) {
                    cpu_state[5] =2;
                    printf("выход за границы памяти");
                    break;
                }

                cpu_state[1] = memory[operand];
                printf("загрузка в аккумулятор | операнд: %d | аккумулятор: %d\n", operand, cpu_state[1]);
                cpu_state[0] += 2;
                break;
        }
    }
}