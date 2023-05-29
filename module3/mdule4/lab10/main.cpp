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
        cout<<"FIO:"<<endl<<"\t"<<"Lastname: "<<lastname<<endl<<"\t"<<"Name: "<<name<<endl<<"\t"<<"Patronymic: "<<patronymic<<endl;
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
        cout<<"Grades:"<<endl;
        for (int i = 0; i < lmax; ++i) {
            cout<<grades[i]<<"\t";
        }
        cout<<endl;
        cout<<"Average: "<<average;
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
        cout<<"Group: "<<group<<endl;
        grade.show();
        cout<<endl;
    }
};

struct Node{
    Student *info;
    Node *next;
    Node *previous;

    Node(){
        info = NULL;
        next = NULL;
    }

    Node(Student *student){
        info = student;
        next = NULL;
    }

    Node(Student *student, Node *previous){
        info = student;
        next = NULL;
        this->previous = previous;
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

            Node *node = new Node(student,last);
            last->next = node;
            last = node;
        }
        first->previous = last;
        last->next = first;
    }

    Node *peek(){
        return first;
    }

    void show(){
        if(!first){
            return;
        }
        Node *temp = this->first;
        do{
            temp->info->show();
            temp = temp->next;
        } while (temp!=first);
    }
};

void print_nodes(Node *top){
    Node *temp = top;
    cout<<"_________________________________"<<endl;
    while (temp->next != top ){
        temp->info->show();
        temp = temp->next;
    }
    cout<<"_________________________________"<<endl;
}



Queue *load_queue(string filename){
    Queue *result = new Queue();
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
            result->enqueue(student);
        }
    }
    return result;
}

void Save(Node *start_node,string filename){
    ofstream out;
    out.open(filename);
    Node *temp = start_node;
    do{
        out<<"FIO:"<<endl<<"\t"<<"Lastname: "<<temp->info->fio.lastname<<endl<<"\t"
           <<"Name: "<<temp->info->fio.name<<endl<<"\t"
           <<"Patronymic: "<<temp->info->fio.patronymic<<endl;
        out<<"Group: "<<temp->info->group<<endl;
        out<<"Grades: "<<endl;
        for (int i = 0; i < 5; ++i) {
            out<<temp->info->grade.grades[i]<<"\t";
        }
        out<<endl;
        out<<"Average: "<<temp->info->grade.average<<endl;
        temp = temp->next;
    }while (temp!=start_node);
    out.close();
}
string filename_input(string type){
    string result;
    cout<<"Write filename for "+type<<endl;
    cin>>result;
    return result;
}

void free_memory(Node *node){
    Node *temp = node;
    Node *next;
    do{
        next = temp->next;
        delete temp;
        temp = next;
    }while(temp==node);
}

bool task(Node *top){
    Node *temp = top;
    bool flag = 0;
    float min_av = temp->info->grade.average;
    if(!top){
        return false;
    }
    do{
        if (temp->info->grade.average < min_av){
            min_av = temp->info->grade.average;
        }
        temp = temp->next;
    } while (temp!=top);

    Node *next;
    do
    {
        if(temp->info->grade.average == min_av)
        {
            flag = 1;
            temp->previous->next = temp->next;
            temp->next->previous = temp->previous;
            next = temp->previous;
            delete temp;
            temp = next;
        }
        temp = temp->next;
    }while(temp!=top);
    return flag;

}



int main() {
    string filename;

    filename = filename_input("input");
    Queue *queue = load_queue(filename);
    if(queue->peek()){
        cout<<"Structer from file"<<endl;
        queue->show();
        if(task(queue->peek())){
            cout << "After changes"<< endl;
            cout<<endl;
            queue->show();
            filename = filename_input("write");
            Save(queue->peek(), filename);
        }
        else
            cout<<"nothing has changes"<<endl;
    } else{
        cout<<"Queue is empty"<<endl;
    }
    free_memory(queue->first);
    delete queue;
    cout<<"Memory is free";
    return 0;
}
