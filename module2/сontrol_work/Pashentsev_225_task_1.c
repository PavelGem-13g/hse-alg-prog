//Пашенцев Павел БИВ225
// 8 вариант задача 1
//Даны целочисленная матрица С[0:N-1,0:M-1] и целочисленный
//массив D[0:K-1]. Написать программу, которая сортирует по
//возрастанию методом пузырька элементы тех строк матрицы С,
//номера которых присутствуют в массиве D. Вычисления оформить в
//виде функции с параметрами.

#include <stdio.h>
#define lmax 1000

void func(int c[lmax][lmax], int n, int m, int d[lmax], int k, int *result){
    int row, changes, temp;
    for (int i = 0; i < k; ++i){
        row = d[i]-1;
        if (row<n){
            do{
                changes = 1;
                for (int column = 0; column < m-1; ++column){
                    if(c[row][column]>c[row][column+1]){
                        temp = c[row][column];
                        c[row][column] = c[row][column+1];
                        c[row][column+1] = temp;
                        changes = 0;
                        *result = 1;
                    }
                }
            } while (!changes);
        }
    }
}

int main() {
    int c[lmax][lmax];
    int n, m;
    int d[lmax];
    int k;
    int result = 0;

    int povtor = 0;
    do{
        printf("Введите N ");
        povtor = scanf("%d", &n);
        while(getchar() != '\n');
    }while(povtor!=1 || (n<2 || 1000<n));


    do{
        printf("Введите M ");
        povtor = scanf("%d", &m);
        while(getchar() != '\n');
    }while(povtor!=1 || (m<2 || 1000<m));

    for (int i = 0; i < n;++i){
        for (int j = 0; j < m; ++j){
            scanf("%d",&c[i][j]);
        }
    }

    printf("Введите K ");
    scanf("%d", &k);
    for (int i = 0; i < k; ++i){
        scanf("%d", &d[i]);
    }

    printf("Введенная матрица: \n");
    for (int i = 0; i < n;++i){
        for (int j = 0; j < m; ++j){
            printf("%d ",c[i][j]);
        }
        printf("\n");
    }

    printf("Массив: \n");
    for (int i = 0; i < k; ++i){
        printf("%d ", d[i]);
    }
    printf("\n");

    func(c,n,m,d,k, &result);

    if (result == 1){
        printf("Обновленная матрица: \n");
        for (int i = 0; i < n;++i){
            for (int j = 0; j < m; ++j){
                printf("%d ",c[i][j]);
            }
            printf("\n");
        }
    } else{
        printf("Матрица не обновилась\n");
    }


    return 0;
}
