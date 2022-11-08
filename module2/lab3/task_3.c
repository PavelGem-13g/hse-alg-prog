#include <stdio.h>

#define lmax 1000

void initialize(int *a){
    for(int *i = a; i < a + lmax; ++i){
        *i = -1001;
    }
}

int input(int min, int max, char phrase[]){
    int result = 0, k = 0;
    do{
        printf(phrase);
        k = scanf("%d", &result);
        while(getchar() != '\n');
    }while(k!=1 && (result<min || max<result));
    return result;
}

void input_array(int *a, int *n){
    *n = input(2, 1000, "Введите число n ");
    for(int *i = a; i < a + *n; ++i){
        *i = input(-1000,1000, "Введите элемент массива ");
    }
}

void output_array(int *a, int n){
    for(int *i = a; i < a + n; ++i){
        printf("%d ", *i);
    }
    printf("\n");
}

void diff(int *a, int *n,  int *b, int *k){
    int *j, *i;
    *k = 0;
    for(i = a; i < a + *n; ++i){
        j = b;
        while(*i != *j && j<b+*k){
            ++j;
        }
        if(*i!=*j){
            ++*(k);
            *j = *i;
        }
    }
}

int main(){
    int a[lmax], b[lmax], n = 0, k = 0;
    initialize(a);
    initialize(b);
    input_array(a, &n);
    output_array(a, n);
    diff(a, &n, b, &k);
    output_array(b, k);
}