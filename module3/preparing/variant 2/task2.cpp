#include <iostream>
#define lmax 1000

using namespace std;

//Дан одномерный массив целых чисел A[0:na-1]. Сформировать
//новый массив, состоящий из различных элементов исходного
//массива, записанных в нем по одному разу. Обработку массива
//оформить в виде функции с параметрами, ввод и вывод данных
//(потоковый) - в основной программе. Обращение к элементам
//массива – при помощи указателя.

int clear(int array[lmax], int n, int result[lmax]){
    int length = 0;
    for (int *i = array; i < array+n; ++i) {
        int *j;
        for (j = result; j < result+length && *j!=*i; ++j);
        if(*j!=*i){
            *(result+length) = *i;
            ++length;
        }
    }
    return length;
}

int main() {
    int na, A[lmax], result[lmax], length;

    cin>>na;
    for (int i = 0; i < na; ++i) {
        cin>>A[i];
    }

    length = clear(A, na, result);
    if(length){
        for (int i = 0; i < length; ++i) {
            cout<<result[i]<<"\t";
        }
    } else{
        cout<<"Пустой массив";
    }


    return 0;
}
