#include <stdio.h>

#define lmax 1000

int input(int min, int max, char phrase[]){
    int k = 0, result = 0;
    do{
        printf(phrase);
        k = scanf("%d", &result);
        while(getchar()!='\n');
    }while(k!=1 || (result < min || max < result));
    return result;
}

void input_matrix(int *a, int n){
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            *(a+n*i+j) = input(-1000, 1000, "Введите элемент матрицы ");
        }
    }
}

void output_matrix(int *a, int n){
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            printf("%d ", *(a+n*i+j));
        }
        printf("\n");
    }
}

void changer(int *a, int n, int z){
    int sum = 0;
    for(int i = 0; i < n; ++i){
        sum += *(a+n*i+i);
    }
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(*(a+n*i+j)==sum){
                *(a+n*i+j) = z;
            }
        }
    }
}

int main(){
    int a[lmax][lmax], n, z;
    n = input(2,1000,"Введите размер матрицы ");
    z = input(-1000, 1000, "Введите число для замены ");
    input_matrix(a, n);
    printf("Введенная матрица \n");
    output_matrix(a, n);
    changer(a, n, z);
    printf("Обновленная матрица \n");
    output_matrix(a, n);
}