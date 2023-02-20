#include <stdio.h>
#include <limits.h>
#include <math.h>
#include <stdlib.h>

#define LMAX 100
#define MAX_VALUE INT_MAX
#define ZERO_CODE 48


// длина числа
int integer_length(int a) {
    int result = 0;
    if (a<0){
        ++result;
    }
    a = abs(a);
    while (a > 0) {
        ++result;
        a /= 10;
    }
    return result;
}

// поиск самого длинного числа
int maximum_length(int array[LMAX][LMAX], int x, int y) {
    int result = 0, temp = 0;
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            temp = integer_length(array[i][j]);
            result = (result > temp) ? result : temp;
        }
    }
    return result;
}

// вывод строки
void print_string(char phrase[]) {
    int i = 0;
    while (phrase[i] != '\0') {
        printf("%c", phrase[i]);
        ++i;
    }
    printf("\n");
}

// вывод матрицы
void prit_matrix(int matrix[LMAX][LMAX], int x, int y) {
    int ml = maximum_length(matrix, x, y);
    int ml_length = integer_length(ml);
    char format[4 + ml_length];//"%-*d "
    format[0] = '%';
    format[1] = '-';
    int i, j;
    for (i = 2, j = ml_length - 1; i < ml_length + 2; ++i, --j) {
        format[i] = ZERO_CODE + ((ml / (int) pow(10, j)) % 10);
    }
    format[i] = 'd';
    format[i + 1] = ' ';
    format[i + 2] = '\0';
    for (i = 0; i < x; ++i) {
        for (j = 0; j < y; ++j) {
            printf(format, matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// ввод значения с ограничениями и проверкой
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
    printf("Лабораторная работа №2\nВыполнил: Пашенцев Павел Владимирович\nЗадача 1\n");
    int n, m, x, y, p, q, B[LMAX][LMAX], A[LMAX][LMAX], C[LMAX][LMAX], max_i = 0, max_j = 0;//почему-то компилятор не даёт поставить больше значения
    n = get_value(2, LMAX, "Введите число n");
    m = get_value(2, LMAX, "Введите число m");
    x = get_value(2, LMAX, "Введите число x");
    y = get_value(2, LMAX, "Введите число y");

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            A[i][j] = get_value(INT_MIN, MAX_VALUE, "Введите элемент матрицы A");
        }
    }

    prit_matrix(A, n, m);

    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            B[i][j] = get_value(INT_MIN, MAX_VALUE, "Введите элемент матрицы B");
        }
    }
    prit_matrix(B, x, y);

    p = (n > x) ? n : x;
    q = (m > y) ? m : y;
    for (int i = 0; i < p; ++i) {
        for (int j = 0; j < q; ++j) {
            if (i < n && i < x && j < m && j < y) {
                C[i][j] = A[i][j] + B[i][j];
            } else {
                if (i < n && j < m) {//&& i >= x && j >= y
                    C[i][j] = A[i][j];
                } else {
                    if (i < x && j < y) {//i >= n && j >= m &&
                        C[i][j] = B[i][j];
                    } else {
                        C[i][j] = 0;
                    }
                }
            }
            if (C[max_i][max_j] < C[i][j]) {
                max_i = i;
                max_j = j;
            }
        }
    }
    int flag = 0;
    int i = 0;
    while (i < n && !flag) {
        if (A[i][0] == C[max_i][max_j]) {
            C[max_i][max_j] = 0;
            flag = 1;
        }
        ++i;
    }
    prit_matrix(C, p, q);
    return 0;
}
// С боков к середине обменять зеркальные значения