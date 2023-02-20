#include <stdio.h>
#include <limits.h>
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

struct Publisher input_publisher(){
    struct Publisher result;
    result.year = input_int(0, INT_MAX, "Введите год издания ");
    puts("Введите название издательства");
    gets(result.name);
    puts("Введите название города");
    gets(result.city);
    return result;
}

void input_array(struct Book books[], int *length){
    *length = input_int(0, lmax, "Введите длину массива ");
    for (int i = 0; i < *length; ++i) {
        puts("Введите название книги");
        gets(books[i].name);
        books[i].price = input_int(0, INT_MAX, "Введите стоимость книги ");
        books[i].countOfPages = input_int(0, INT_MAX, "Введите количество страниц ");
        puts("Введите ФИО автора");
        gets(books[i].author);
        books[i].publisher = input_publisher();
    }
}

void get_rows(struct Book books[lmax], int length, int price){
    printf("_____________________________________\nОтчет\n_____________________________________\n");
    int max_i = 0;
    for (int i = 1; i < length; ++i) {
        if(books[i].price>books[max_i].price){
            max_i = i;
        }
    }
    puts(books[max_i].author);
}


int main() {
    printf("Лабораторная работа №6\nВыполнил:Пашенцев Павел Владимирович\nЗадача 1\n");
    struct Book books[lmax];
    int length;
    input_array(books, &length);
    print_Book_array(books, length);
    get_rows(books, length, 1000);
    return 0;
}
