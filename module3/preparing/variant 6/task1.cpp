#include <iostream>
#define lmax 1000

using namespace std;

//Дана матрица X[0:n-1][0:m-1] и массив Y[0:k-1]. Написать
//программу, которая вычисляет массив Z, состоящий из элементов
//X, расположенных между первым четным и последним нечетным
//элементами каждой строки, и присутствующих в массиве Y. Ввод
//данных (потоковый), вывод результата и вычисления оформить в
//виде отдельных функций с параметрами. Обращение к элементам
//матрицы и массива – по индексу.

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
    for (int i = 0; i < n; ++i) {
        int first_chet = -1, last_nechet = -1;
        for (int j = 0; j < m; ++j) {
            if(matrix[i][j]%2==0 and first_chet==-1){
                first_chet = j;
            }
            if(matrix[i][j]%2!=0){
                last_nechet = j;
            }
        }
        if(first_chet!=-1 and last_nechet!=-1){
            int start = 0, end = 0;
            if(first_chet>last_nechet){
                start = last_nechet;
                end = first_chet;
            } else{
                start = first_chet;
                end = last_nechet;
            }
            for (int j = start+1; j < end; ++j) {
                int flag = 0;
                for (int l = 0; l < k and !flag; ++l) {
                    if(matrix[i][j]==array[l]){
                        flag = 1;
                    }
                }
                if(flag){
                    result[(*length)++] = matrix[i][j];
                }
            }
        }
    }
}

int main() {
    int X[lmax][lmax], n, m;
    int Y[lmax], k;
    int Z[lmax], length;

    input_matrix(X, &n, &m);
    input_array(Y, &k);

    output_matrix(X, n, m);
    output_array(Y, k);

    func(X, n, m, Y, k, Z, &length);
    if(length){
        output_array(Z, length);
    } else{
        cout<<"Пустой массив";
    }

    return 0;
}
