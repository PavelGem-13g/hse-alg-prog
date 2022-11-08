#include <stdio.h>
#include <limits.h>
#define lmax 1000

int input(int min, int max, char phrase[]){
    int result = 0, k = 0;
    do{
        printf(phrase);
        k = scanf("%d", &result);
        while (getchar()!='\n');
    } while (k!=1 && (result<min || max<result));
    return result;
}
void input_matrix(int *a, int *n, int *m){
    *n = input(2, 1000, "Введите число n ");
    *m = input(2, 1000, "Введите число m ");
    for (int i = 0; i < *n; ++i){
        for (int j = 0; j < *m; ++j){
            *(a+i*(*m)+j) = input(0,1000, "Введите значение матрицы ");
        }
    }
}

void output_matrix(int *a, int n, int m){
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            printf("%d ", *(a+i*m+j));
        }
        printf("\n");
    }
}

int s(int *a, int n , int m){
    int min = INT_MAX, temp_max = 0;
    for (int j = 0; j < m; ++j){
        temp_max = *(a+j);
        for (int i = 0; i < n; ++i){
            if (temp_max<*(a+i*m+j)){
                temp_max = *(a+i*m+j);
            }
        }
        if (temp_max<min){
            min = temp_max;
        }
    }
    return min;
}

int main(){
    int a[lmax][lmax], n, m, result = 0;
    input_matrix(a, &n, &m);
    output_matrix(a, n, m);
    result = s(a, n, m);
    printf("Результат вычисления программы %d \n", result);
    return 0;
}