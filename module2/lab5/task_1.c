// Создать файл для хранения действительных чисел, вводимых с клавиатуры.
// Прочитать этот файл и вычислить максимальное по абсолютной величине

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define lmax 1000


int main() {
    FILE *fileStream;
    char filename[lmax];
    double input, max = -1, temp;
    printf("Введите название файла:\n");
    gets(filename);

    if(!(fileStream = fopen(filename, "w+"))){
        printf("Ошибка при открытии файла");
        exit(1);
    }

    fseek(fileStream,0L,SEEK_SET);

    printf("Введите числовую последовательность. Введите строку, чтобы закончить ввод\n");
    while (scanf("%lf", &input)){
        fprintf(fileStream, "%lf \n", input);
    }

    fclose(fileStream);

    if(!(fileStream = fopen(filename, "r+"))){
        printf("Ошибка при открытии файла");
        exit(1);
    }
    while (!feof(fileStream)){
        fscanf(fileStream, "%lf", &temp);
        if (fabs(max)<fabs(temp)){
            max = temp;
        }
    }

    if(max==-1){
        printf("Дан пустой файл");
    } else{
        printf("Максимальное по модулю число %lf", max);
    }

    return 0;
}
