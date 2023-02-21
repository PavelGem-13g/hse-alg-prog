#include <iostream>
#define lmax 10000

using namespace std;

// Пашенцев Павел Владимирович БИВ225 Задача 2

//Дан одномерный массив целых чисел A[0:na-1]. Удалить путем
//сдвига все элементы массива, равные его минимальному элементу.
//Дополнительный массив не использовать. Обработку массива
//оформить в виде функции, ввод и вывод данных (потоковый) – в
//основной программе. Обращение к элементам массива – при помощи
//указателя.

void func(int array[lmax], int *na){
    int min = *array;
    for (int *i = array; i < array + *na; ++i) {
        if(*i<min){
            min = *i;
        }
    }
    int *i = array;
    int flag = 0;
    while (i < array + *na) {
        flag = 0;
        if(*i==min){
            for(int *j = i; j < array + *na; ++j){
                *j = *(j+1);
            }
            --(*na);
            i = array;
            flag = 1;
        }
        if(!flag){
            ++i;
        }
    }
}

int main() {
    int A[lmax], na;

    cout<<"Введите длину массива ";
    cin>>na;
    for (int i = 0; i < na; ++i) {
        cout<<"Введите элемент массива ";
        cin>>*(A+i);
    }

    func(A, &na);

    if(na!=0){
        for(int *i = A; i < A+na;++i){
            cout<<*i<<"\t";
        }
    } else{
        cout<<"Пустой результирующий массив ";
    }

    return 0;
}
