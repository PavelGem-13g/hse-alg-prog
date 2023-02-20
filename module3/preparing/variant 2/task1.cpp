#include <iostream>
#define lmax 1000

using namespace std;

//Дана матрица X[0:n-1][0:m-1] и массив Y[0:k-1]. Написать
//программу, которая вычисляет массив Z, состоящий из элементов
//X, расположенных между минимальным и максимальным элементами
//каждой строки, и присутствующих в массиве Y. Ввод данных
//(потоковый), вывод результата и вычисления оформить в виде
//отдельных функций с параметрами. Обращение к элементам матрицы
//и массива – по индексу.

void input_matrix(int matrix[lmax][lmax], int *n, int *m){
    cin>>*n;
    cin>>*m;
    for (int i = 0; i < *n; ++i) {
        for (int j = 0; j < *m; ++j) {
            cin>>matrix[i][j];
        }
    }
}

void input_array(int array[lmax], int *n){
    cin>>*n;
    for (int i = 0; i < *n; ++i) {
        cin>>array[i];
    }
}

void output_matrix(int matrix[lmax][lmax], int n, int m){
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout<<matrix[i][j]<<"\t";
        }
        cout<<endl;
    }
}

void output_array(int array[lmax], int n){
    for (int i = 0; i < n; ++i) {
        cout<<array[i]<<"\t";
    }
    cout<<endl;
}


int func(int matrix[lmax][lmax], int n, int m, int array[lmax], int k, int result[lmax]){
    int length = 0;
    for (int i = 0; i < n; ++i) {
        int minj = 0, maxj = 0;
        for (int j = 0; j < m; ++j) {
            if(matrix[i][j]>matrix[i][maxj]){
                maxj = j;
            }
            if(matrix[i][j]<matrix[i][minj]){
                minj = j;
            }

            if(maxj!=minj){
                int start = 0, end = 0;
                if(maxj>minj){
                    start = minj;
                    end = maxj;
                } else{
                    start = maxj;
                    end = minj;
                }
                for (int l = start+1; l < end; ++l) {
                    int i1;
                    for (i1 = 0; i1 < k && array[i1]!=matrix[i][l]; ++i1);
                    if(array[i1]==matrix[i][l]){
                        result[length++]=matrix[i][l];
                    }
                }
            }
        }
    }
    return length;
}


int main() {
    int n, m, X[lmax][lmax];
    int k, Y[lmax];
    int length, Z[lmax];

    input_matrix(X, &n, &m);
    input_array(Y, &k);

    output_matrix(X, n, m);
    output_array(Y, k);

    length = func(X, n, m, Y, k, Z);
    if(length){
        output_array(Z, length);
    } else{
        cout<<"Пустой массив";
    }


    return 0;
}
