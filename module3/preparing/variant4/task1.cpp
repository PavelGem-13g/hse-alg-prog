#include <iostream>
#define lmax 1000

using namespace std;

//Дана матрица X[0:n-1][0:m-1] и массив Y[0:k-1]. Написать
//программу, которая вычисляет массив Z, состоящий из элементов
//X, расположенных между первым четным и максимальным нечетным
//элементами каждой строки, если все эти элементы (между первым
//четным и максимальным нечетным) присутствуют в массиве Y.
//Ввод данных (потоковый), вывод результата и вычисления
//оформить в виде отдельных функций с параметрами. Обращение к
//элементам матрицы и массива – по индексу.

void input_array(int array[lmax], int *n){
    cin>>*n;

    for (int i = 0; i < *n; ++i) {
        cin>>array[i];
    }
}

void output_array(int array[lmax], int n){
    for (int i = 0; i < n; ++i) {
        cout<<array[i]<<"\t";
    }
    cout<<endl;
}

void input_matrix(int array[lmax][lmax], int *n, int *m){
    cin>>*n;
    cin>>*m;
    for (int i = 0; i < *n; ++i) {
        for (int j = 0; j < *m; ++j) {
            cin>>array[i][j];
        }
    }
}

void output_matrix(int matrix[lmax][lmax], int n, int m){
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << matrix[i][j] << "\t";
        }
        cout<<endl;
    }
}

void func(int matrix[lmax][lmax], int n, int m, int array[lmax], int k, int result[lmax], int *length){
    for (int i = 0; i < n; ++i) {
        int chet = -1, nechet = -1;
        for (int j = 0; j < m; ++j) {
            if(matrix[i][j]%2==0 and chet==-1){
                chet = j;
            }
            if(nechet==-1 && matrix[i][j]%2==1){
                nechet = j;
            } else if(matrix[i][j]%2==1 and matrix[i][j]>matrix[i][nechet]){
                nechet = j;
            }
        }

        if(chet!=-1 && nechet!=-1){
            int start = 0, end = 0;
            if(chet>nechet){
                start = nechet;
                end = chet;
            } else{
                start = chet;
                end = nechet;
            }
            int flag = 1;
            for (int j = start+1; j < end and flag; ++j) {
                flag = 0;
                for (int l = 0; l < k and !flag; ++l) {
                    if(array[l]==matrix[i][j]){
                        flag = 1;
                    }
                }
            }
            if(flag){
                for (int j = start+1; j < end and flag; ++j) {
                    result[(*length)++] = matrix[i][j];
                }
            }
        }
    }
}

int main() {
    int n, m, X[lmax][lmax];
    int k, Y[lmax];
    int length, Z[lmax];

    input_matrix(X, &n, &m);
    input_array(Y, &k);

    output_matrix(X, n, m);
    output_array(Y, k);

    func(X, n, n, Y, k, Z, &length);

    output_array(Z, length);


    return 0;
}
