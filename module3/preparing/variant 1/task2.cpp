#include <iostream>
#define lmax 1000

using namespace std;

//Дан одномерный массив целых чисел A[0:na-1]. Удалить путем
//сдвига все четные элементы массива. Дополнительный массив не
//использовать. Обработку массива оформить в виде функции с
//параметрами, ввод и вывод данных (потоковый) – в основной
//программе. Обращение к элементам массива – при помощи
//указателя.

int clear(int array[lmax], int n){
    int *place = array;
    int length = 0;
    for (int i = 0; i < n; ++i) {
        if(*(array+i)%2!=0){
            *place = *(array+i);
            ++place;
            ++length;
        }
    }
    return length;
}

void print_array(int array[lmax], int n){
    cout<<"Массив"<<endl;
    for (int *i = array; i < array+n; ++i) {
        cout<<*i<<"\t";
    }
}

int main() {
    int a[lmax], na = 0;
    cout<<"Введите длину"<<endl;
    cin>>na;
    cout<<"Введите значения"<<endl;
    for (int i = 0; i < na; ++i) {
        cin>>a[i];
    }
    print_array(a, na);

    na = clear(a, na);
    print_array(a, na);

    return 0;
}
