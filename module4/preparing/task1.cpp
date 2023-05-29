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

    void clear(){
        Node *temp = top;
        while(temp){
            int flag = 0;
            Node *temp2 = temp->next;
            while (temp2 && !flag){
                if(temp->value == temp2->value){
                    if(!temp->previous){
                        Node *next = temp->next;
                        temp->previous->next = temp->next;
                        delete temp;
                        temp = next;
                    } else if(!temp2->next){
                        temp->previous->next = NULL;
                        delete temp2;
                        temp2 = NULL;
                    } else{
                        temp->previous->next = temp->next;
                        temp->next->previous = temp->previous;
                        delete temp;
                        temp = temp2->next;
                    }
                } else{
                    temp2 = temp2->next;
                }
            }
            temp = temp->next;
        }
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
