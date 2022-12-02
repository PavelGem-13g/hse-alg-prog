// Пашенцев Павел БИВ225
//Вариант 8 задача 2
//Дана матрица В[0:N-1,0:N-1] вещественного типа. Написать
//программу, которая обнуляет главную диагональ матрицы, если
//сумма элементов под побочной диагональю положительная.
//Вычисления оформить в виде функции с параметрами.
#include <stdio.h>
#define lmax 1000

void func(int b[lmax][lmax], int n, int *result){
    int sum = 0;
    for (int i = 0; i < n; ++i){
        for(int j = n-i; j < n; ++j){
            sum += b[i][j];
        }
    }
    if (sum>0){
        for(int i = 0; i < n; ++i){
            b[i][i] = 0;
        }
        *result = 1;
    }
}

int main() {
    int b[lmax][lmax];
    int n, result = 0;

    int povtor = 0;
    do{
        printf("Введите N ");
        povtor = scanf("%d", &n);
        while(getchar() != '\n');
    }while(povtor!=1 || (n<2 || 1000<n));



    for (int i = 0; i < n;++i){
        for (int j = 0; j < n; ++j){
            scanf("%d",&b[i][j]);
        }
    }

    printf("Введенная матрица: \n");
    for (int i = 0; i < n;++i){
        for (int j = 0; j < n; ++j){
            printf("%d ",b[i][j]);
        }
        printf("\n");
    }

    func(b, n, &result);
    if (result==1){
        printf("Матрица изменена\nМатрица:\n");
        for (int i = 0; i < n;++i){
            for (int j = 0; j < n; ++j){
                printf("%d ",b[i][j]);
            }
            printf("\n");
        }
    } else{
        printf("Матрица не изменена");
    }
}