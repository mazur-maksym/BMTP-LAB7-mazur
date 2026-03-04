#include <stdio.h>
#include <string.h>
#include <windows.h>

#define MAX 1000

void to_lower_utf8(char *s) {
    unsigned char *p = (unsigned char *)s;
    while (*p) { // A-Z
        if (*p >= 'A' && *p <= 'Z') {
            *p += 32;
            p++;
        }
        else if (*p == 0xD0 && *(p+1) >= 0x90 && *(p+1) <= 0x9F) { // а-п
            *(p+1) += 0x20;
            p += 2;
        }
        else if (*p == 0xD0 && *(p+1) >= 0xA0 && *(p+1) <= 0xAF) { // р-я
            *p = 0xD1;
            *(p+1) -= 0x20;
            p += 2;
        }
        else {
            p++;
        }
    }
}

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    char sentence[MAX];
    char copy[MAX];

    printf("╔══════════════════════════════════════════╗\n");
    printf("║         ЛАБОРАТОРНА РОБОТА №7            ║\n");
    printf("║  Пошук слова у введеному реченні         ║\n");
    printf("╠══════════════════════════════════════════╣\n");
    printf("║  Розробник: Мазур Максим                  ║\n");
    printf("║  Група: КН-25                            ║\n");
    printf("║  ЦНТУ, 2026                              ║\n");
    printf("╚══════════════════════════════════════════╝\n\n");

    printf("Введіть речення (закінчується '.', '!' або '?'):\n> ");
    fgets(sentence, MAX, stdin);

    int len = strlen(sentence);
    if (sentence[len-1] == '\n') {
        sentence[len-1] = '\0';
        len--;
    }

    char last = sentence[len-1];
    if (last != '.' && last != '!' && last != '?') {
        printf("Помилка: речення має закінчуватись на '.', '!' або '?'\n");
        system("pause");
        return 1;
    }

    strcpy(copy, sentence);
    to_lower_utf8(copy);

    if (strstr(copy, "програма") != NULL)
        printf("\nРезультат: слово \"програма\" є у реченні.\n");
    else
        printf("\nРезультат: слово \"програма\" відсутнє у реченні.\n");

    system("pause");
    return 0;
}
