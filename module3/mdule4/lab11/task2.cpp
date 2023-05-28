#include <iostream>

using namespace std;

struct Node{
    Node *left;
    Node *right;
    int value;

    Node(int value){
        left = NULL;
        right = NULL;
        this->value = value;
    }

    Node(Node *left, Node *right, int value){
        this->left = left;
        this->right = right;
        this->value = value;
    }

    int add(Node *node){
        //левая ветвь
        if(this->value>node->value){
            if(this->left){
                return this->left->add(node);
            } else{
                this->left = node;
                return 1;
            }
        } else{
            if(this->right){
                return this->right->add(node);
            } else{
                this->right = node;
                return 1;
            }
        }
        return 0;
    }


    Node *copy(){
        Node *result = NULL;
        if(left && right){
            result = new Node(left->copy(), right->copy(), value);
        } else if(!left && right){
            result = new Node(NULL, right->copy(), value);
        } else if(left && !right){
            result = new Node(left->copy(), NULL, value);
        } else if (!left && !right){
            result = new Node(value);
        }
        return result;
    }

    void show(){
        if(left){
            left->show();
        }
        cout<<value<<"\t";
        if(right){
            right->show();
        }
    }

    void release(){
        if(right){
            right->release();
            delete right;
        }
        if(left){
            left->release();
            delete left;
        }
        right = NULL;
        left = NULL;
    }
};

struct Tree{
    Node *top;

    Tree(){
        top = NULL;
    }

    Tree(Node *tree_top){
        if(tree_top){
            if(tree_top->left && tree_top->right){
                top = new Node(tree_top->left->copy(), tree_top->right->copy(), tree_top->value);
            } else if(!tree_top->left && tree_top->right){
                top = new Node(NULL, tree_top->right->copy(), tree_top->value);
            } else if(tree_top->left && !tree_top->right){
                top = new Node(tree_top->left, NULL, tree_top->value);
            }
            else if(!tree_top->left && !tree_top->right){
                top = new Node(tree_top->value);
            }
        }
    }

    void add(int value){
        Node *node = new Node(value);
        if(!top){
            top = node;
        }
        else{
            top->add(node);
        }
    }

    void show(){
        if(top){
            cout<<"Вывод дерева"<<endl;
            top->show();
            cout<<endl;
        } else{
            cout<<"Пустое дерево"<<endl;
        }
    }

    Tree *copy(){
        Tree *result;
        if(this->top){
            result = new Tree(this->top);
            result->top->copy();
        } else{
            result = new Tree();
        }
        return result;
    }

    void release(){
        top->release();
        delete top;
    }
};


void deleteNodes(Node *&node, int value) {
    if (node == nullptr) {
        return;
    }

    deleteNodes(node->left, value);
    deleteNodes(node->right, value);

    if (node->value < value) {
        Node* temp = node;
        if (node->left == nullptr) {
            node = node->right;
            delete temp;
        } else if (node->right == nullptr) {
            node = node->left;
            delete temp;
        } else {
            Node* minRight = node->right;
            while (minRight->left != nullptr) {
                minRight = minRight->left;
            }

            node->value = minRight->value;
            deleteNodes(node->right, minRight->value);
        }
    }
}

int main() {
    Tree *tree = new Tree();
    Tree *tree2;
    int value;

    cout<<"Введите минимальное для дерева значение"<<endl;
    cin>>value;

    cout<<"Введите последовательность чисел для дерева, строка - конец последовательности"<<endl;
    int input;
    while (cin>>input){
        tree->add(input);
    }


    tree2 = tree->copy();
    deleteNodes(tree->top, value);

    cout<<"Копия исходного дерева"<<endl;
    tree2->show();
    cout<<"Преобразованное дерево"<<endl;
    tree->show();

    cout<<"Память очищена";
    tree->release();
    tree2->release();
    return 0;
}
