// Выделить из каждой строки и напечатать подстроки не содержащие символов '.', ',', ';', ':';
// Среди выделенных подстрок найти подстроку начинающуюся с наибольшего (но не нулевого) числа цифр;
// Преобразовать исходную строку, которой принадлежит найденная подстрока, следующим образом: вставить три звездочки перед последней цифрой.

#include <stdio.h>
#include <string.h>
#define lmax 1000

int input_integer(int min, int max, char phrase[]){
    int result = 0;
    int k = 0;
    do{
        puts(phrase);
        k = scanf("%d", &result);
        while(getchar() != '\n');
    }while(k!=1 || (result < min || max < result));
    return result;
}

void print_string(char phrase[]){
    while(*phrase){
        printf("%c", phrase);
        ++phrase;
    }
    printf("\n");
}

void input_array(char *array[lmax], int *k){
    *k = input_integer(2, 1000, "Введите длину массива ");
    for (int i = 0; i < *k; ++i){
        puts("Введите новый элемент ");
        gets(array[i]);
    }
}

void output_array(char *array[lmax], int k){
    puts("\nВывод массива ");
    for (int i = 0; i < k; ++i){
        puts(array[i]);
    }
}

int is_integer(char str){
    //int result = 0;
    //int temp = ord(str);
    //return 48<temp && temp<58;
}

void select_string(char array[lmax][lmax], int k, char output[lmax][lmax]){
    char avoid_symbols[4] = {'.', ',',';',':'};
    char *temp_symbol = NULL;
    int temp_result = 0;
    for (int i = 0; i < k; ++i){
        temp_symbol = array[i];
        while(temp+1 && temp_result){
            temp_result=strcspn(temp, avoid_symbols);
            ++temp;
        }
    }
}

int main(){
    char *strings[lmax], k = 3;
    input_array(strings, &k);
    //printf("%d", is_integer('a'));
    output_array(strings, k);
}