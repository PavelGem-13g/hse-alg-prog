//Сформировать линейный двунаправленный стек. Удалить из него все неповторяющиеся элементы.
#include <iostream>

using namespace std;

struct Node{
    int value;
    Node *next;
    Node *previous;

    Node(){
        value = 0;
        next = NULL;
        previous = NULL;
    }

    Node(int value){
        this->value = value;
        next = NULL;
        previous = NULL;
    }

    Node(int value, Node *previous){
        this->value = value;
        this->previous = previous;
    }
};

struct Stack{
    Node *top;

    Stack(){
        top = NULL;
    }

    void add(int value){
        Node *node = new Node(value, top);
        node->next = top;
        top = node;
    }

    void show(){
        cout<<endl;
        Node *temp = top;
        while (temp){
            cout<<temp->value<<"\t";
            temp = temp->next;
        }
    }
};

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
            Node *node = new Node()
        }
    }
};

int main() {
    int n;
    cin>>n;
    Stack *stack = new Stack();
    for (int i = 0; i < n; ++i) {
        int temp;
        cin>>temp;
        stack->add(temp);
    }

    stack->show();
    stack->clear();
    stack->show();

    return 0;
}
