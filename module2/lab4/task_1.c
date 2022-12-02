// Выделить из каждой строки и напечатать подстроки не содержащие символов '.', ',', ';', ':';
// Среди выделенных подстрок найти подстроку начинающуюся с наибольшего (но не нулевого) числа цифр;
// Преобразовать исходную строку, которой принадлежит найденная подстрока, следующим образом: вставить три звездочки перед последней цифрой.

#include <stdio.h>
#include <string.h>
#include <ctype.h>

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

void input_array(char array[lmax][lmax], int *k){
    *k = input_integer(2, 1000, "Введите длину массива ");
    for (int i = 0; i < *k; ++i){
        puts("Введите новый элемент ");
        gets(array[i]);
    }
}

void output_array(char array[lmax][lmax], int k){
    for (int i = 0; i < k; ++i){
        puts(array[i]);
    }
}

void select_string(char array[lmax][lmax], int n, char output[lmax][lmax], int numbers[lmax], int *k){
    char avoid_symbols[4] = {'.', ',',';',':'};
    char *start, *temp_symbol;
    int flag;
    for (int i = 0; i < n; ++i){
        temp_symbol = array[i];
        start = NULL;
        while (*temp_symbol)
        {
            flag = 0;
            for(int j = 0; j < 4; ++j) {
                if (*temp_symbol == avoid_symbols[j]) {
                    flag = 1;
                    break;
                }
            }
            if (flag && start){
                strncpy(&output[*k][0], start, temp_symbol - start);
                output[*k][temp_symbol - start] = '\0';
                numbers[*k] = i;
                start = NULL;
                ++(*k);
            } else if (!flag && !start){
                start = temp_symbol;
            }
            ++temp_symbol;
        }
        if(!*temp_symbol && start){
            strncpy(&output[*k][0], start, temp_symbol - start);
            output[*k][temp_symbol - start] = '\0';
            numbers[*k] = i;
            ++(*k);
        }
    }
}

int number(char strings[lmax][lmax], int n){
    int result = -1,max_length = 0;
    for(int i = 0; i < n; ++i){
        char *temp_symbol = &strings[i][0];
        while (isdigit(*temp_symbol)){
            ++temp_symbol;
        }
        if(temp_symbol-&strings[i][0]>max_length){
            max_length = temp_symbol-&strings[i][0];
            result = i;
        }
    }
    return result;
}

void add_stars(char string[lmax]){
    unsigned long length = strlen(string);
    char *temp_symbol = &string[length - 1];
    while (!isdigit(*temp_symbol)){
        *(temp_symbol+3) = *temp_symbol;
        --temp_symbol;
    }
    *(temp_symbol+3) = *temp_symbol;
    for(int i = 0; i < 3; ++i){
        *(temp_symbol+i) ='*';
    }
}

int main(){
    char strings[lmax][lmax], clear[lmax][lmax];
    int n = 0, k = 0, numbers[lmax], num;
    input_array(strings, &n);
    puts("_____________\nВывод исходного массива ");
    output_array(strings, n);
    select_string(strings, n, clear, numbers, &k);
    puts("_____________\nВывод массива подстрок");
    output_array(clear, k);
    num = number(clear,k);
    if(num==-1){
        printf("_____________\nНе найдено строк с цифрами\n");
    } else{
        add_stars(strings[numbers[num]]);
        puts("_____________\nВывод исходного измененного массива ");
        output_array(strings, n);
    }
}