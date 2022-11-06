#include <stdio.h>

int input(int min, int max, char phrase[]){
    int result = 0;
    int k = 0;
    do{
        printf(phrase);
        k = scanf("%d", &result);
        while(getchar() != '\n');
    }while(k!=1 && (result < min || max > result));
    return result;
}

int formula(int k){
    if(k==1){
        return 3;
    }
    return (2*k+1)*formula(k - 1);
}

int main(){
    int k = input(0,1000,"Введите число k ");
    int result = formula(k);
    printf("Вычисленное значание %d", result);
    return 0;
}