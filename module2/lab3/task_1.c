#include <stdio.h>
#define MAX 1000

int input(int min, int max, char phrase[]){
    int result = 0;
    int k = 0;
    do{
        printf(phrase);
        k = scanf("%d", &result);
        while(getchar() != '\n');
    }while(k!=1 || (result < min || max < result));
    return result;
}

int f(int k){
    if(k==0){
        return 1;
    }
    return (2*k+1)*f(k - 1);
}

int main(){
    printf("Лабораторная работа №3\nВыполнил: Пашенцев Павел Владимирович\nЗадача 1\n");
    int k = input(0,MAX,"Введите число k ");
    int result = f(k);
    printf("Вычисленное значение %d \n", result);
    return 0;
}