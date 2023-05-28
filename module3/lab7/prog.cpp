#include <stdio.h>
#include <stdlib.h>
#define CLR while (getchar()!='\n')
#define lmax 1000

struct node {
    struct node *next;
    int info;
};
//Организовать очередь.
// 2-8 Для исходного списка решить следующую задачу: вставить до минимального элемента заданное число A1, а после него – заданное число A2;
// 3-1 Для полученного списка решить следующую задачу: выбрать из списка все четные элементы и сформировать из них новую очередь;
struct node *queue(){
    int n;
    struct node *add, *last, *first = NULL;

    FILE *fileStream;
    char fileName[lmax];
    printf("Введите название файла\n");
    scanf("%s", fileName);
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


    if (!fscanf(fileStream, "%d\n", &n) || n<=0){
        return first;
    }
    else{
        first = (struct node*) malloc(sizeof( struct node));
        first->info=n;
        last=first;
        while (!feof(fileStream) && fscanf(fileStream, "%d\n", &n)){
            add = (struct node*) malloc(sizeof( struct node));
            add->info = n;
            last->next = add;
            last = add;
        }
        last->next = NULL;
    }
    return (first);
}

void output(struct node *list){
    FILE *fileStream;
    char filename[lmax];
    printf("Введите название записываемого файла:\n");
    scanf("%s", filename);
    if(!(fileStream = fopen(filename, "w"))){
        printf("Ошибка при открытии файла");
        exit(1);
    }

    struct node *temp = list;
    while (temp){
        fprintf(fileStream, "%d ", temp->info);
        temp = temp->next;
    }
}

struct node *insert2(struct node *queue, int A1, int A2){
    struct node *temp = queue, *previous = NULL, *premin = NULL,  *mini = queue, *item1, *item2;
    while (temp){
        if(temp->info<mini->info){
            mini = temp;
            premin = previous;
        }
        previous = temp;
        temp = temp->next;
    }

    item1 = (struct node*) malloc(sizeof (struct node*));
    item1->info = A1;
    item1->next = NULL;

    item2 = (struct node*) malloc(sizeof (struct node*));
    item2->info = A2;
    item2->next = NULL;

    if(!premin && !mini->next){
        item1->next = mini;
        mini->next = item2;
        queue = item1;
    }
    else if(!premin && mini->next){
        item1->next = mini;
        item2->next = mini->next;
        mini->next = item2;
        queue = item1;
    } else if(premin && mini && !mini->next){
        mini->next = item2;
        item1->next = mini;
        premin->next = item1;
    } else{
        item2->next = mini->next;
        mini->next = item2;
        item1->next = mini;
        premin->next = item1;
    }
    return queue;
}


struct node *chet(struct node *list){
    struct node *temp = list;
    struct node *add, *last = NULL, *result = NULL;
    while(temp){
        if (temp->info%2==0){
            if(result == NULL){
                result = (struct node*) malloc(sizeof (struct node));
                result->info = temp->info;
                last = result;
            } else{
                add = (struct node*) malloc(sizeof (struct node));
                add->info = temp->info;
                last->next = add;
                last = add;
            }
        }
        temp = temp->next;
    }
    if(last){
        last->next = NULL;
    }
    return result;
}

void clear(struct node *list){
    struct node *temp = list, *temp_next = list;
    while (temp_next){
        temp_next = temp->next;
        free(temp);
        temp = temp_next;
    }
}

void print(struct node *queue){
    puts("Вывод списка:");
    struct node *temp = queue;
    while (temp){
        printf("%d ", temp->info);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    printf("Лабораторная работа №7\nВыполнил:Пашенцев Павел Владимирович\n");

    int A1, A2;
    puts("Введите число A1: ");
    scanf("%d", &A1);

    puts("Введите число A2: ");
    scanf("%d", &A2);

    struct node *list = queue();


    struct node *chetn;
    print(list);
    if (!list){
        puts("Пустой список");
    } else{
        list = insert2(list, A1, A2);
        print(list);
        chetn = chet(list);
        if(chetn){
            print(chetn);
        } else{
            puts("Нет четных чисел");
        }
        output(chetn);
        clear(list);
        clear(chetn);
        puts("Память успешно очищена");
    }
    return 0;
}