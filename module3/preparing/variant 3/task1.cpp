#include <iostream>
#define lmax 1000

using namespace std;
//Дана матрица A[0:n-1][0:m-1] и массив B[0:k-1]. Написать
//программу, которая вычисляет массив C, состоящий из элементов
//A, расположенных между первым положительным и последним
//отрицательным элементами каждого столбца, если произведение
//всех этих элементов (расположенных между положительным и
//отрицательным) присутствует в массиве B. Ввод данных
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

void func(int matrix[lmax][lmax], int n, int m, int array[lmax], int k, int result[lmax], int *length){
    int start, end, p;
    for (int i = 0; i < m; ++i) {
        int positive = -1, negative = -1;
        for (int j = 0; j < n; ++j) {
            if(positive==-1 and matrix[j][i]>0){
                positive = j;
            }
            if(matrix[j][i]<0){
                negative = j;
            }
        }
        if(negative != positive and positive!=-1 and negative!=-1){
            if(negative > positive){
                start = positive;
                end = negative;
            } else{
                start = negative;
                end = positive;
            }
            p = 1;
            for (int j = start+1; j < end; ++j) {
                p*=matrix[j][i];
            }
            int j;
            for (j = 0; j < k and p!=array[j]; ++j);
            if(j<k){
                for (int l = start+1; l < end; ++l) {
                    result[(*length)++] = matrix[l][i];
                }
            }
        }
    }
}

int main() {
    int A[lmax][lmax], n, m;
    int B[lmax], k;
    int C[lmax], length;

    input_matrix(A, &n, &m);
    input_array(B, &k);

    output_matrix(A, n, m);
    output_array(B, k);

    func(A, n, m, B, k, C, &length);

    if(length){
        output_array(C, length);
    } else{
        cout<<"Пустой массив";
    }

    return 0;
}
