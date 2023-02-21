#include <iostream>
#define lmax 1000

using namespace std;

//Дан одномерный массив целых чисел A[0:na-1]. Упорядочить по
//возрастанию методом установки все его элементы, расположенные
//после первого нечетного элемента. Обработку массива оформить в
//виде функции, ввод и вывод данных (потоковый) – в основной
//программе. Обращение к элементам массива – при помощи
//указателя.

void func(int array[lmax], int n){
    int temp;
    int *i;
    for (i = array; i < array+n and *i%2==0; ++i);
    if(i < array+n and *i%2!=0){
        for (int *j = i+1; j < array+n; ++j) {
            for (int *k = j+1; k < array+n; ++k) {
                if(*j>*k){
                    temp = *k;
                    *k = *j;
                    *j = temp;
                }
            }
        }
    }
}


int main() {
    int A[lmax], na;

    cin>>na;
    for (int i = 0; i < na; ++i) {
        cin>>*(A+i);
    }

    func(A, na);

    for (int i = 0; i < na; ++i) {
        cout<<*(A+i)<<"\t";
    }

    return 0;
}
