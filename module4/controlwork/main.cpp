//Сформировать линейный двунаправленный стек.
// Отсортировать по возрастанию методом установки его элементы,
// расположенные до первого нуля.

#include <iostream>
#include <fstream>

using namespace std;

struct Node{
    int value;
    Node *next;
    Node *previous;

    Node(){
        this->value = 0;
        this->next = NULL;
        this->previous = NULL;
    }

    Node(int value){
        this->value = value;
        this->next = NULL;
        this->previous = NULL;
    }

    Node(int value, Node *next){
        this->value = value;
        this->next = next;
        this->previous = NULL;
    }
};

struct Stack{
    Node *top;
    Node *tail;

    Stack(){
        top = NULL;
        tail = NULL;
    }

    void add(int value){
        if(!tail){
            tail = new Node(value);
            top = tail;
        } else{
            Node *node  = new Node(value, top);
            if(top){
                top->previous = node;
            }
            top = node;
        }
    }

    void show(){
        Node *temp = top;

        while (temp){
            cout<<temp->value<<"\t";
            temp = temp->next;
        }
        cout<<endl;
    }

    void revers_show(){
        Node *temp = tail;

        while (temp){
            cout<<temp->value<<"\t";
            temp = temp->previous;
        }
        cout<<endl;
    }

    int sort(){
        Node *temp = top;
        while (temp && temp->value!=0){
            temp = temp->next;
        }
        if(temp && temp->value==0){
            Node *start = this->top;
            Node *end = temp;
            if(start==end){
                return 0;
            } else{
                Node *iterator = start;
                while (iterator!=end->previous){
                    Node *iterator2 = iterator->next;
                    if(iterator2){
                        while (iterator2 && iterator2!=end){
                            if(iterator->value>iterator2->value){
                                swap(iterator, iterator2);
                            }
                            iterator2 = iterator2->next;
                        }
                        iterator = iterator->next;
                    }
                }
            }
        } else{
            return 0;
        }
        return 1;
    }

    void swap(Node *first, Node *second){
        int temp = first->value;
        first->value = second->value;
        second->value = temp;
    }
};

Stack *file_input(string filename){
    Stack *result = new Stack();
    ifstream in;
    in.open(filename);
    if(in.peek()!=EOF){
        while (!in.eof()){
            int temp;
            in>>temp;
            result->add(temp);
        }
    }
    return result;
}

void file_output(Stack *stack, string filename){
    ofstream out;
    out.open(filename);
    Node *temp = stack->top;
    while (temp){
        out<<temp->value<<"\t";
        temp = temp->next;
    }
    out.close();
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
    cout<<"Введите название входного файла"<<endl;
    cin>>filename;
    Stack *stack = new Stack();
    stack = file_input(filename);
    if(!stack->top){
        cout<<"Введен пустой список";
    } else{
        cout<<"Стек в обычном порядке"<<endl;
        stack->show();
        cout<<"Стек в обратном порядке"<<endl;
        stack->revers_show();
        if(!stack->sort()){
            cout<<"Нет элементов для сортировки";
        } else{
            cout<<"Отсортированный список"<<endl;
            stack->show();

            cout<<"Введите называние выходного файла"<<endl;
            cin>>filename;
            file_output(stack, filename);
        }
    }

    free_memory(stack->top);
    cout<<"Память очищена";
    return 0;
}
