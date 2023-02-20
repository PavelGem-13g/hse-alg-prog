#include <iostream>
#define lmax 1000

using namespace std;

//Дан одномерный массив целых чисел A[0:na-1]. Вставить ноль до
//каждого элемента массива, равного его минимальному элементу.
//Дополнительный массив не использовать. Обработку массива
//оформить в виде функции с параметрами, ввод и вывод данных
//(потоковый) – в основной программе. Обращение к элементам
//массива – при помощи указателя.

void func(int array[lmax], int *n){
    int min = *array;
    for(int *i = array; i < array + *n; ++i){
        if(min>*i){
            min = *i;
        }
    }
    for (int i = *n-1; i > -1; --i) {
        if(array[i]==min){
            for (int j = ++(*n); j > i-1; --j) {
                array[j] = array[j-1];
            }
            array[i] = 0;
        }
    }
}

int main() {
    int A[lmax], na;

    cin>>na;
    for (int i = 0; i < na; ++i) {
        cin>>A[i];
    }

    func(A, &na);

    for (int i = 0; i < na; ++i) {
        cout<<A[i]<<"\t";
    }

    return 0;
}
