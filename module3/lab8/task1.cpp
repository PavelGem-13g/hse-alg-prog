#include <iostream>
#define lmax 1000

using namespace std;

void inputArray(int array[lmax], int *length){
    cout<<"Введите длину массива"<<endl;
    cin>>*length;
    for (int *i = array; i < array+*length; ++i) {
        cout<<"Введите элемент массива ";
        cin>>*i;
    }
}

void outputArray(int array[lmax], int length){
    cout<<"Массив:"<<endl;
    for (int *i = array; i < array+length; ++i) {
        cout<<*i<<"\t";
    }
    cout<<endl;
}

void func(int A[lmax], int na, int B[lmax], int nb, int C[lmax], int *nc){
    *nc = 0;
    for (int *i = A; i < A+na; ++i) {
        if (*i>0){
            int *j;
            for (j = B; j < B + nb and *i!=*j; ++j);
            if (*i==*j){
                int *k;
                for (k = C; k < C+*nc and *i!=*k; ++k);
                if (*k==*(C+*nc)){
                    C[(*nc)++] = *i;
                }
            }
        }
    }
}

int main() {
    cout<<"Лабораторная работа №7\nВыполнил:Пашенцев Павел Владимирович\n";

    int A[lmax], na, B[lmax], nb;
    int C[lmax], nc;

    inputArray(A, &na);
    inputArray(B, &nb);

    outputArray(A, na);
    outputArray(B, nb);


    func(A, na, B, nb, C, &nc);
    if (nc>0){
        outputArray(C, nc);
    } else{
        cout<<"Пустой результирующий массив";
    }

    return 0;
}
