#include <stdio.h>
#include <stdlib.h>
#include <strings.h>


#define lmax 1000


struct Publisher{
    int year;
    char name[lmax];
    char city[lmax];
};

struct Book{
    char name[lmax];
    int price;
    int countOfPages;
    char author[lmax];
    struct Publisher publisher;
};

void print_Book_to_stream(struct Book book, FILE *fileStream){
    fprintf(fileStream, "Название книги\t");
    fputs(book.name, fileStream);
    fprintf(fileStream, "\n");
    fprintf(fileStream, "Цена\t %d\n", book.price);
    fprintf(fileStream, "Количество страниц\t %d\n", book.countOfPages);
    fprintf(fileStream, "ФИО автора\t");
    fputs(book.author, fileStream);
    fprintf(fileStream, "\n");
    fputs("Издательство:", fileStream);
    fprintf(fileStream, "    Год издания\t %d\n", book.publisher.year);
    fprintf(fileStream, "    Название\t");
    fputs(book.publisher.name, fileStream);
    fprintf(fileStream, "\n");
    fprintf(fileStream, "    Город\t");
    fputs(book.publisher.city, fileStream);
    fprintf(fileStream, "\n");
    fprintf(fileStream, "\n");
}

void print_Book(struct Book book){
    printf("Название книги\t");
    puts(book.name);
    printf("Цена\t %d\n", book.price);
    printf("Количество страниц\t %d\n", book.countOfPages);
    printf("ФИО автора\t");
    puts(book.author);
    puts("Издательство:");
    printf("    Год издания\t %d\n", book.publisher.year);
    printf("    Название\t");
    puts(book.publisher.name);
    printf("    Город\t");
    puts(book.publisher.city);
    printf("\n");
}

void print_Book_array(struct Book books[lmax], int length){
    printf("_____________________________________\n");
    for (int i = 0; i < length; ++i) {
        print_Book(books[i]);
    }
}

int input_int(int min, int max, char phrase[]){
    int result = 0, k = 0;
    do{
        printf(phrase);
        k = scanf("%d", &result);
        while (getchar()!='\n');
    } while (k!=1 || (result<min || max<result));
    return result;
}

void input_array(struct Book books[], int *length){
    FILE *fileStream;
    char fileName[lmax];
    printf("Введите название файла\n");
    gets(fileName);
    if(!(fileStream = fopen(fileName, "r+"))){
        printf("Ошибка при открытии файла");
        exit(1);
    }

    fseek(fileStream,0L,SEEK_END);
    if(!ftell(fileStream)){
        printf("Введен пустой файл");
        exit(1);
    }
    fseek(fileStream,0L,SEEK_SET);

    fscanf(fileStream, "%d\n", length);
    for (int i = 0; i < *length; ++i) {
        fgets(books[i].name, lmax, fileStream);
        books[i].name[strlen(books[i].name)-1]='\0';
        fscanf(fileStream, "%d\n", &books[i].price);
        fscanf(fileStream, "%d\n", &books[i].countOfPages);
        fgets(books[i].author, lmax, fileStream);
        books[i].author[strlen(books[i].author)-1]='\0';
        fscanf(fileStream, "%d\n", &books[i].publisher.year);
        fgets(books[i].publisher.name, lmax, fileStream);
        books[i].publisher.name[strlen(books[i].publisher.name)-1]='\0';
        fgets(books[i].publisher.city, lmax, fileStream);
        books[i].publisher.city[strlen(books[i].publisher.city)-1]='\0';
    }
}

void get_rows(struct Book books[lmax], int length, int price){
    FILE *fileStream;
    char filename[lmax];
    printf("Введите название записываемого файла:\n");
    gets(filename);
    if(!(fileStream = fopen(filename, "w"))){
        printf("Ошибка при открытии файла");
        exit(1);
    }

    struct Book *max_book = &books[0];
    for (int i = 1; i < length; ++i) {
        if((books+i)->price>max_book->price){
            max_book = books+i;
        }
    }

    fprintf(fileStream, "_____________________________________\nОтчет\n_____________________________________\n");
    fputs(max_book->author);
}


int main() {
    printf("Лабораторная работа №6\nВыполнил:Пашенцев Павел Владимирович\nЗадача 2\n");
    FILE *file;
    struct Book books[lmax];
    int length;
    input_array(books, &length);
    print_Book_array(books, length);
    get_rows(books, length, 1000);
    return 0;
}
