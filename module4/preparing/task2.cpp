//Сформировать линейную однонаправленную очередь. Удалить из нее все повторяющиеся элементы.
#include <iostream>

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
        this->next = NULL;
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
        Node *node = new Node(value);
        if(!first){
            first = node;
            last = first;
        } else{
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
    }

    void clear(){
        Node *temp = first;
        while (temp){
            Node *temp2 = temp->next;
            int flag = 0;
            while (temp2){
                if(te)
                    temp2 = temp2->next;
            }
            temp = temp->next;
        }
    }
};

int main() {
    int n;
    cin>>n;
    Queue *queue = new Queue();
    for (int i = 0; i < n; ++i) {
        int temp;
        cin>>temp;
        queue->enqueue(temp);
    }

    queue->show();

    return 0;
}
