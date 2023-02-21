#include <iostream>
#define lmax 1000

using namespace std;

//Дан одномерный массив целых чисел A[0:na-1]. Удалить путем
//сдвига все элементы массива, равные его минимальному элементу.
//Дополнительный массив не использовать. Обработку массива
//оформить в виде функции, ввод и вывод данных (потоковый) – в
//основной программе. Обращение к элементам массива – при помощи
//указателя.

void func(int array[lmax], int na){
    int min = *array;
    for (int *i = array; i < array + na; ++i) {
        if(*i<min){
            min = *i;
        }
    }
    for (int *i = array+na-1; i >= array; --i) {
        if(*i==min){
            for(int *j = )
        }
    }
}

int main() {
    int A[lmax], na;

    cin>>na;
    for (int i = 0; i < na; ++i) {
        cin>>A[i];
    }



    return 0;
}
