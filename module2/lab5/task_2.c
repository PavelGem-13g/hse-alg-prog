// Создать текстовый файл средствами редактора (т. е. в ?Блокноте?).
// Прочитать этот файл построчно и произвести в каждой строке следующее действие:
// удалить путем сдвига все строчные латинские буквы.
// Записать каждую полученную строку в новый текстовый файл и вывести полученные строки из файла на экран.
// Имена входного и выходного файла задаются пользователем.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#define lmax 1000

void read(char strings[lmax][lmax], int *n){
    FILE *fileStream;
    char filename[lmax];
    printf("Введите название читаемого файла:\n");
    gets(filename);
    if(!(fileStream = fopen(filename, "r+"))){
        printf("Ошибка при открытии файла");
        exit(1);
    }
    fseek(fileStream,0L,SEEK_END);
    if(!ftell(fileStream)){
        printf("Введен пустой файл");
        exit(1);
    }
    fseek(fileStream,0L,SEEK_SET);
    *n = 0;
    printf("Начало чтения значений...\n");
    while (!feof(fileStream)){
        fgets(strings[*n], lmax, fileStream);
        strings[*n][strlen(strings[*n])-1] = '\0';
        ++(*n);
    }
    fclose(fileStream);
    printf("Конец чтения значений\n");
}

void write(char strings[lmax][lmax], int n){
    FILE *fileStream;
    char filename[lmax];
    printf("Введите название записываемого файла:\n");
    gets(filename);
    if(!(fileStream = fopen(filename, "w"))){
        printf("Ошибка при открытии файла");
        exit(1);
    }
    for (int i = 0; i < n; ++i){
        fputs(strings[i], fileStream);
        fputs("\n", fileStream);
    }
    fclose(fileStream);
}

void print(char strings[lmax][lmax], int n){
    for(int i = 0; i < n ; ++i){
        puts(strings[i]);
    }
}

void delete(char strings[lmax][lmax], int n){
    char *temp, *position;
    for(int i = 0; i < n; ++i){
        temp = &strings[i][0];
        position = &strings[i][0];
        while (*temp){
            if(!('a'<= tolower(*temp) && tolower(*temp)<='z')){
                *position = *temp;
                ++position;
            }
            ++temp;
        }
        *position = *temp;
    }

}

int main() {
    FILE *fileStream;
    char filename[lmax], strings[lmax][lmax];
    int n;
    double input, max = -1, temp;
    printf("Лабораторная работа №1\nВыполнил:Пашенцев Павел Владимирович\nЗадача 2\n");
    read(strings, &n);
    printf("Вывод введенного файла:\n");
    print(strings,n);
    delete(strings, n);
    printf("Вывод измененного массива:\n");
    print(strings,n);
    write(strings, n);
    return 0;
}
