#include <iostream>
#define lmax 1000

using namespace std;

void input(int array[lmax], int *length){
    cout<<"Введите длину матрицы"<<endl;
    cin>>*length;
    for (int *i = array; i < array+*length*(*length); ++i) {
        cout<<"Введите элемент матрицы ";
        cin>>*i;
    }
}

void output(int array[lmax], int length){
    cout<<"Матрица:";
    for (int i = 0; i < length*length; ++i) {
        if(i%length==0){
            cout<<endl;
        }
        cout<<array[i]<<"/t";
    }
    cout<<endl;
}

int determinantGauss(int *A, int n) {
    double det = 1;
    int i, j, k, sign = 0;
    for (i = 0; i < n - 1; i++) {
        if (A[i * n + i] == 0) { // if diagonal element is 0
            for (j = i + 1; j < n; j++)
                if (A[j * n + i] != 0)
                    break;
            if (j == n)
                return 0;
            for (k = i; k < n; k++)
                swap(A[i * n + k], A[j * n + k]);
            sign++; // count number of row interchanges
        }
        for (j = i + 1; j < n; j++) {
            double tmp = A[j * n + i] / A[i * n + i];
            for (k = i; k < n; k++)
                A[j * n + k] -= tmp * A[i * n + k];
        }
    }
    for (i = 0; i < n; i++)
        det *= A[i * n + i];
    if (sign % 2 == 1)
        det = -det;
    return det;
}

int func(int *matrix, int n){
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            sum+=*(matrix+n*i+j);
        }
    }
    if(sum>0){
        return determinantGauss(matrix, n);
    } else{
        return -1;
    }
}


int main() {
    int matrix[lmax], n;

    input(matrix, &n);
    output(matrix,n);
    int result = 0;
    result = func(matrix, n);
    if(result==-1){
        cout<<"Сумма элементов меньше нуля";
    } else{
        cout<<"Сумма элементов больше нуля"<<endl;
        cout<<"Определитель матрицы равен "<<result;
    }

    return 0;
}
