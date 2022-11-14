#include <stdio.h>
#include <limits.h>
#define lmax 1000

int input(int min, int max, char phrase[]){
    int result = 0, k = 0;
    do{
        printf(phrase);
        k = scanf("%d", &result);
        while(getchar() != '\n');
    }while(k!=1 || (result<min || max<result));
    return result;
}

void input_array(int *a, int *n){
    *n = input(2, 1000, "Введите число n ");
    for(int *i = a; i < a + *n; ++i){
        *i = input(-INT_MIN,INT_MAX, "Введите элемент массива ");
    }
}

void output_array(int *a, int n){
    for(int *i = a; i < a + n; ++i){
        printf("%d ", *i);
    }
    printf("\n");
}

void diff(int *a, int *n, int *b, int *m){
    int *j, *i;
    for(i = a; i < a + *n; ++i){
        j = b;
        while(*i != *j && j<b+*m){
            ++j;
        }
        if(*i!=*j){
            ++*(m);
            *j = *i;
        }
    }
}

void counter(int *a, int n, int *unic,int *counts, int *k){
    int j, i;
    int flag;
    for(i = 0; i < n; ++i){
        j = 0;
        flag = 1;
        while(j<*k && flag){
            if(*(a+i)==*(unic+j)){
                ++(*(counts+j));
                flag = 0;
            }
            ++j;
        }
        if(*(a+i)!=*(unic+j) && flag){
            *(unic+j) = *(a+i);
            *(counts+j) = 1;
            ++(*k);
        }
    }
}

int main(){
    printf("Лабораторная работа №3\nВыполнил: Пашенцев Павел Владимирович\nЗадача 3\n");
    int a[lmax], b[lmax], unic[lmax], counts[lmax], n = 0, k = 0, m = 0;
    input_array(a, &n);
    printf("Массив А\n");
    output_array(a, n);

    counter(a, n, unic, counts, &k);
    printf("Различные значения массива А\n");
    output_array(unic, k);
    printf("Повторены столько раз соответственно\n");
    output_array(counts,k);

    diff(a,&n,b,&m);
    printf("Значения массива B\n");
    output_array(b, m);
}