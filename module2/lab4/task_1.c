// Выделить из каждой строки и напечатать подстроки не содержащие символов '.', ',', ';', ':';
// Среди выделенных подстрок найти подстроку начинающуюся с наибольшего (но не нулевого) числа цифр;
// Преобразовать исходную строку, которой принадлежит найденная подстрока, следующим образом: удалить путем сдвига все латинские буквы.

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define lmax 1000

void inputArray(char array[lmax][lmax], int *k){

    *k = 0;
    int count = 0;
    do{
        puts("Введите длину массива");
        count = scanf("%d", k);
        while(getchar() != '\n');
    }while(count != 1 || (*k < 2 || 1000 < *k));

    for (int i = 0; i < *k; ++i){
        puts("Введите новый элемент ");
        gets(array[i]);
    }
}

void outputArray(char array[lmax][lmax], int k){
    for (int i = 0; i < k; ++i){
        puts(array[i]);
    }
}

void selectString(char array[lmax][lmax], int n, char output[lmax][lmax], int numbers[lmax], int *k){
    char avoid_symbols[4] = {'.', ',',';',':'};
    char *start, *temp_symbol;
    int flag;
    for (int i = 0; i < n; ++i){
        temp_symbol = array[i];
        start = NULL;
        while (*temp_symbol){
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

void changeString(char string[lmax]){
/*    char *temp_symbol = string, *position = string;
    while (*temp_symbol){
        if (!(('A'<=*temp_symbol && *temp_symbol <= 'Z') || ('a'<=*temp_symbol && *temp_symbol <= 'z'))){
            *position = *temp_symbol;
            ++position;
        }
        ++temp_symbol;
    }
    *position = *temp_symbol;*/
    char result_string[lmax];
    char *temp_symbol = string, *position = result_string;
    while (*temp_symbol){
        if(('0'<=*temp_symbol && *temp_symbol<='9')
        ||('a'<=tolower(*temp_symbol) && tolower(*temp_symbol)<='z')){
            *position = *temp_symbol;
            ++position;
        } else{
            *position = *temp_symbol;
            ++position;
            *position = *temp_symbol;
            ++position;
        }
        ++temp_symbol;
    }
    strcpy(string, result_string);
}

int main(){
    char strings[lmax][lmax], clear[lmax][lmax];
    int n = 0, k = 0, numbers[lmax], num;
    inputArray(strings, &n);
    puts("_____________\nВывод исходного массива ");
    outputArray(strings, n);
    selectString(strings, n, clear, numbers, &k);
    puts("_____________\nВывод массива подстрок");
    outputArray(clear, k);
    num = number(clear,k);
    if(num==-1){
        printf("_____________\nНе найдено строк с цифрами\n");
    } else{
        changeString(strings[numbers[num]]);
        puts("_____________\nВывод исходного измененного массива ");
        outputArray(strings, n);
    }
}
