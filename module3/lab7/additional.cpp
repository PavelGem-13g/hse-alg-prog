#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *next;
    int info;
};
//Создать стек из вводимых пользователем целых чисел. Удалить все элементы между первым и последним отрицательным элементом.
struct node *stack(){
    int n;
    struct node *p, *lst;
    lst = NULL;
    printf("Введите числа \n");
    while (scanf("%d", &n)){
        p = (struct node*) malloc(sizeof(struct node));
        p->info = n;
        p->next = lst;
        lst = p;
    }
    return (lst);
}

void delete(struct node *list){
struct node *temp = list;
struct node *firstNeg = NULL, *lastNeg = NULL;
while (temp){
if(temp->info<0 && !firstNeg){
firstNeg = temp;
} else if(temp->info<0 && firstNeg){
lastNeg = temp;
}
temp = temp->next;
}

if(firstNeg && lastNeg){
struct node *next;
temp = firstNeg->next;
while (temp!=lastNeg){
next = temp->next;
free(temp);
temp = next;
}
firstNeg->next = lastNeg;
} else{
printf("Невозможно удалить элементы стека\n");
}
}

void print(struct node *list){
    puts("Вывод списка:");
    struct node *temp = list;
    while (temp){
        printf("%d ", temp->info);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct node *lst = stack();
    print(lst);
    delete(lst);
    print(lst);
    return 0;
}