//Сформировать два связанных списка (стеки). Данные для каждого списка расположены в отдельном файле.
// Сформировать новую очередь, состоящую их элементов первого списка, повторяющихся во втором списке
// не более двух раз (но присутствующих в нем).
#include <iostream>
#include <fstream>

using namespace std;

struct Node{
    int value;
    Node *next;

    Node(){
        value = 0;
        next = NULL;
    }

    Node(int value){
        this->value = value;
        next = NULL;
    }
};

struct Stack{
    Node *top;

    Stack(){
        top = NULL;
    }

    void add(int value){
        Node *node = new Node(value);
        node->next = top;
        top = node;
    }

    void show(){
        Node *temp = top;
        while (temp){
            cout<<temp->value<<"\t";
            temp = temp->next;
        }
        cout<<endl;
    }

    void free(){
        Node *temp = top;
        while (temp){
            Node *next = temp->next;
            delete temp;
            temp = next;
        }
    }
};

Stack *load_stack_file(string filename){
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

struct Queue{
    Node *first;
    Node *last;

    Queue(){
        first = NULL;
        last = NULL;
    }

    void enqueue(int value){
        if(!first){
            first = new Node(value);
            last = first;
        } else{
            Node *node = new Node();
            last->next = node;
            last = node;
        }
    }

    void show(){
        Node *temp = first;
        while (temp){
            cout<<temp->value<<"\t";
            temp = temp->next;
        }
        cout<<endl;
    }
};

Queue *repeat_in_2(Stack *stack, Stack *stack2){
    Queue *result = new Queue();
    Node *temp = stack->top;
    while (temp){
        int count = 0;
        Node *temp2 = stack2->top;
        while(temp2 && count<=2){
            if(temp2->value==temp->value){
                ++count;
            }
            temp2 = temp2->next;
        }
        if(count<2){
            result->enqueue(temp->value);
        }
        temp = temp->next;
    }
    return result;
}



int main() {
    string filename;
    Stack *stack = new Stack();
    Stack *stack2 = new Stack();

    cout<<"Введите название файла 1"<<endl;
    cin>>filename;
    stack = load_stack_file(filename);

    cout<<"Введите название файла 2"<<endl;
    cin>>filename;
    stack2 = load_stack_file(filename);

    stack->show();
    stack2->show();

    Queue *queue = repeat_in_2(stack, stack2);
    stack->free();
    stack2->free();
    queue->show();



    return 0;
}
