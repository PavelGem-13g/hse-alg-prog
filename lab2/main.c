#include <stdio.h>
#include <limits.h>
#include <locale.h>

#define LMAX SHRT_MAX


int count_contains(int a, int z) {
    int result = 0, temp = 0;
    while (a > 0) {
        temp = a % 10;
        if (z == temp) {
            ++result;
        }
        a /= 10;
    }
    return result;
}


void prit_array(int array[], int length) {
    for (int i = 0; i < length; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");
}


void print_string(char phrase[]) {
    int i = 0;
    while (phrase[i] != '\0') {
        printf("%c", phrase[i]);
        ++i;
    }
    printf("\n");
}


int get_value(int min, int max, char phrase[]) {
    int result = 0;
    int count = 0;
    do {
        print_string(phrase);
        count = scanf("%d", &result);
        while (getchar() != '\n');
    } while (count != 1 || (min > result || result > max));
    return result;
}


int main() {
    setlocale(LC_ALL, "RU");
    printf("Лабораторная работа №2 \nВыполнил: Пашенцев Павел Владимирович\nЗадача 2\n");
    int n = 0, z = 0, A[LMAX], B[LMAX], count = 0, temp = 0, k = 0;
    n = get_value(1, LMAX, "Введите число n");
    z = get_value(0, 10, "Введите цифру z");
    for (int i = 0; i < n; ++i) {
        A[i] = get_value(INT_MIN, INT_MAX, "Введите новый элемент");
    }
    prit_array(A, n);
    for (int i = 0; i < n; ++i) {
        temp = count_contains(A[i], z);
        if (temp > 0) {
            B[k] = A[i];
            ++k;
        }
        count += temp;
    }
    printf("%d встречается в массиве %d раз\n", z, count);
    prit_array(B, k);
    return 0;
}
