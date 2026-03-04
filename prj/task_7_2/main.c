#include <stdio.h>
#include <windows.h>

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    int numbers[14];
    int target[3] = {150, 1000, 10000};
    int count = 0;

    printf("╔══════════════════════════════════════════╗\n");
    printf("║         ЛАБОРАТОРНА РОБОТА №7            ║\n");
    printf("║  Підрахунок чисел 150, 1000 або 10000    ║\n");
    printf("╠══════════════════════════════════════════╣\n");
    printf("║  Розробник: Мазур Максим                 ║\n");
    printf("║  Група: КН-25                            ║\n");
    printf("║  ЦНТУ, 2026                              ║\n");
    printf("╚══════════════════════════════════════════╝\n\n");

    printf("Введіть 14 чисел через пробіл:\n> ");
    for (int i = 0; i < 14; i++) {
        scanf("%d", &numbers[i]);
    }

    for (int i = 0; i < 14; i++) {
        for (int j = 0; j < 3; j++) {
            if (numbers[i] == target[j])
                count++;
        }
    }

    printf("\nКількість чисел рівних 150, 1000 або 10000: %d\n", count);

    system("pause");
    return 0;
}
