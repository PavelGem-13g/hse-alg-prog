#include <iostream>
#include <fstream>

using namespace std;

#define lmax 5

struct Fio{
    string lastname;
    string name;
    string patronymic;

    Fio(string lastname, string name, string patronymic){
        this->lastname = lastname;
        this->name = name;
        this->patronymic = patronymic;
    };
    void show(){
        cout<<"ФИО:"<<endl<<"\t"<<"Фамилия: "<<lastname<<endl<<"\t"<<"Имя: "<<name<<endl<<"\t"<<"Отчество: "<<patronymic<<endl;
    }
};

struct Grade{
    int grades[lmax];
    float average;

    Grade(int grades[lmax]){
        std::copy(grades, grades+lmax, this->grades);
        float sum = 0;
        for (int i = 0; i < 5; ++i) {
            sum += grades[i];
        }
        this->average = sum/5;
    }

    void show(){
        cout<<"Оценки:"<<endl;
        for (int i = 0; i < lmax; ++i) {
            cout<<grades[i]<<"\t";
        }
        cout<<endl;
        cout<<"Средняя оценка: "<<average;
    }
};

struct Student{
    Fio fio;
    string group;
    Grade grade;

    Student(string lastname, string name, string patronymic, string group, int grades[lmax]):
            fio(lastname, name, patronymic),
            grade(grades){
        this->group = group;
    };

    void show(){
        fio.show();
        cout<<"Группа: "<<group<<endl;
        grade.show();
        cout<<endl;
    }
};

struct Node{
    Student *info;
    Node *next;

    Node(){
        info = NULL;
        next = NULL;
    }

    Node(Student *student){
        info = student;
        next = NULL;
    }
};

struct Stack{
    Node *top;

    Stack(){
        top = NULL;
    }

    void push(Student *student){
        Node *node = new Node(student);
        node->next = top;
        top = node;
    }

    Node *pop(){
        return top;
    }

    void show(){
        Node *temp = top;
        while (temp){
            temp->info->show();
            temp = temp->next;
        }
    }
};

struct Queue{
    Node *first;
    Node *last;

    Queue(){
        first = NULL;
        last = first;
    }

    void enqueue(Student *student){
        if(!first){
            first = new Node(student);
            last = first;
        } else{
            Node *node = new Node(student);
            last->next = node;
            last = node;
        }
    }

    Node *peek(){
        return first;
    }

    void show(){
        Node *temp = this->first;
        while (temp){
            temp->info->show();
            temp = temp->next;
        }
    }
};

void print_nodes(Node *top){
    Node *temp = top;
    cout<<"_________________________________"<<endl;
    while (temp){
        temp->info->show();
        temp = temp->next;
    }
    cout<<"_________________________________"<<endl;
}

Queue *best_students(Stack *students){
    auto *result = new Queue();
    Node *temp = students->pop();
    while (temp){
        if(temp->info->grade.average>=8){
            result->enqueue(temp->info);
        }
        temp = temp->next;
    }
    //print_nodes(result->peek());
    return result;
}

Stack *load_stack(string filename){
    Stack *result = new Stack();
    ifstream in;
    in.open(filename);
    if(in.peek()!=EOF){
        while (!in.eof()){
            string lastname, name, patronomic, gruop;
            int grades[lmax];
            in>>lastname>>name>>patronomic>>gruop;
            for (int i = 0; i < lmax; ++i) {
                in>>grades[i];
            }
            Student *student = new Student(lastname, name, patronomic, gruop, grades);
            result->push(student);
        }
    }
    return result;
}

void save(Node *start_node,string filename){
    ofstream out;
    out.open(filename);
    Node *temp = start_node;
    while (temp){
        out<<"ФИО:"<<endl<<"\t"<<"Фамилия: "<<temp->info->fio.lastname<<endl<<"\t"
           <<"Имя: "<<temp->info->fio.name<<endl<<"\t"
           <<"Отчество: "<<temp->info->fio.patronymic<<endl;
        out<<"Группа: "<<temp->info->group<<endl;
        out<<"Оценки: "<<endl;
        for (int i = 0; i < 5; ++i) {
            out<<temp->info->grade.grades[i]<<"\t";
        }
        out<<endl;
        out<<"Средняя оценка: "<<temp->info->grade.average;
        temp = temp->next;
    }
    out.close();
}

string filename_input(string type){
    string result;
    cout<<"Введите название для "+type+" файла"<<endl;
    cin>>result;
    return result;
}

void free_memory(Node *node){
    Node *temp = node;
    Node *next;
    while (temp){
        next = temp->next;
        delete temp;
        temp = next;
    }
}

int main() {
    string filename;

    filename = filename_input("входного");
    Stack *stack = load_stack(filename);
    if(stack->pop()){
        cout<<"Вывод входных значений (стек)"<<endl;
        print_nodes(stack->pop());

        Queue *best = best_students(stack);
        if(best->peek()){
            cout<<"Вывод лучших студентов (очередь)"<<endl;
            print_nodes(best->peek());
        } else{
            cout<<"Нет студентов-отличников"<<endl;
        }

        filename = filename_input("выходного");
        save(best->peek(), filename);

        free_memory(best->peek());
        delete best;
    } else{
        cout<<"Введен пустой стек"<<endl;
    }

    free_memory(stack->pop());
    delete stack;
    cout<<"Память очищена";

    return 0;
}
