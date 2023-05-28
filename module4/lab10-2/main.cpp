#include <iostream>
#include <fstream>
//#include <algorithm>

using namespace std;

#define lmax 5

struct Fio{
    string lastname;
    string name;
    string patronymic;
};

struct Grade{
    int grades[lmax];
    float average;
};

struct Student{
    Fio fio;
    string group;
    Grade grade;
};

struct Node{
    Student *info;
    Node *next;
};

void show_node(Node node){
    cout<<node.info->fio.lastname<<"\t"<<node.info->fio.name<<"\t"<<node.info->fio.patronymic<<endl;
}

struct Stack{
    Node *top;
};

void push(Stack *stack,Student *student){
    Node *node = new Node();
    node->info = student;
    node->next = stack->top;
    stack->top = node;
}
//void save(string filename){
//    ofstream out;
//    out.open(filename);
//    Node *temp = this->pop();
//    while (temp){
//        out<<"ФИО:"<<endl<<"\t"<<"Фамилия: "<<temp->info->fio.lastname<<endl<<"\t"
//           <<"Имя: "<<temp->info->fio.name<<endl<<"\t"
//           <<"Отчество: "<<temp->info->fio.patronymic<<endl;
//        out<<"Группа: "<<temp->info->group<<endl;
//        out<<"Оценки: "<<endl;
//        for (int i = 0; i < 5; ++i) {
//            out<<temp->info->grade.grades[i]<<"\t";
//        }
//        out<<endl;
//        out<<temp->info->grade.average;
//        temp = temp->next;
//    }
//    out.close();
//}

struct Queue{
    Node *first;
    Node *last;
};

void enqueue(Queue *queue, Student *student){
    if(!queue->first){
        Node *node = new Node();
        node->info = student;
        queue->first = node;
        queue->last = queue->first;
    } else{
        Node *node = new Node();
        node->info = student;
        queue->last->next = node;
        queue->last = node;
    }
}

void print_nodes(Node *top){
    Node *temp = top;
    while (temp){
        show_node(*temp);
        temp = temp->next;
    }
}

Queue *best_students(Stack *students){
    Queue *result = new Queue();
    Node *temp = students->top;
    while (temp){
        if(temp->info->grade.average>=8){
            Student *student = temp->info;//охуеть баг конечно, такие баги нахуй надо слать, кто блять знал, что он воспринимает это как констату сука
            //здесь находится вызов команды, меняющий student
            enqueue(result, student);
            //аналогично здесь
        }
        temp = temp->next;
    }
    return result;
}



int main() {
    int grades[] = {2, 4, 1, 5, 3};
    int grades2[] = {10, 10, 10, 10, 10};
    Stack *stack = new Stack();
    Student *stud = new Student();//"Пашенцев", "Павел", "Владимирови", "БИВ225", grades
    stud->fio.lastname = "Пашенцев";
    stud->fio.name = "Павел";
    stud->fio.patronymic = "Владимирови";
    stud->group = "БИВ225";
    copy(grades, grades+lmax, stud->grade.grades);
    stud->grade.average = 3;

    Student *stud2 = new Student();//"asdasd", "asdasdasda", "asdasdasdas", "БИВ225", grades2
    stud2->fio.lastname = "asdasd";
    stud2->fio.name = "asdasdasda";
    stud2->fio.patronymic = "asdasdasdas";
    stud2->group = "БИВ224";
    copy(grades2, grades2+lmax, stud2->grade.grades);
    stud2->grade.average = 10;

    push(stack, stud);
    push(stack, stud2);
    //print_nodes(stack.top);


    //stack.show();
    //Node *temp = stack.pop();

//    int i = 0;
//    while (temp){
//        temp->info->show();
//        temp = temp->next;
//    }
//

    //Тут работает
    Queue queue = Queue();
    enqueue(&queue, stud);
    enqueue(&queue, stud2);
    //print_nodes(queue.first);


//    temp = queue.peek();
//    int i = 0;
//    while (temp){
//        temp->info->show();
//        temp = temp->next;
//    }

//    Тут не работает, из-за обнуления элемента списка внутри вывода
    Queue *best = best_students(stack);
    print_nodes(best->first);
    //best.show();

//    Node *temp = best.peek();
//    while (temp){
//        temp->info->show();
//        temp = temp->next;
//    }
    return 0;
}
