#include <iostream>
#define lmax 1000

using namespace std;

//Дана матрица A[0:n-1][0:m-1] и массив B[0:k-1]. Написать
//программу, которая вычисляет массив C, состоящий из элементов
//A, расположенных между минимальным и максимальным элементами
//каждого столбца, если сумма этих элементов (расположенных
//между минимальным и максимальным) отсутствует в массиве B.
//Ввод данных (потоковый), вывод результата и вычисления
//оформить в виде отдельных функций с параметрами. Обращение к
//элементам матрицы и массива – по индексу.

int func(int matrix[lmax][lmax], int n, int m, int array[lmax], int k, int result[lmax]){
    int length = 0;
    for (int i = 0; i < m; ++i) {
        int minj = 0, maxj = 0, sum = 0;

        for (int j = 0; j < n; ++j) {
            if (matrix[j][i] < matrix[minj][i]){
                minj = j;
            }

            if (matrix[j][i] > matrix[maxj][i]){
                maxj = j;
            }
        }

        if(maxj != minj){
            int start = 0, end = 0;
            if (maxj > minj){
                start = minj;
                end = maxj;
            } else{
                start = maxj;
                end = minj;
            }


            for (int j = start; j < end+1; ++j) {
                sum += matrix[j][i];
            }

            int j = 0;
            for (; j < k && array[j]!=sum; ++j);
            if(j==k){
                for (int l = start; l < end+1; ++l) {
                    result[length] = matrix[l][i];
                    length+=1;
                }
            }
        }

    }
    return length;
}

void print_matrix(int matrix[lmax][lmax], int n, int m){
    cout<<"Матрица"<<endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout<<matrix[i][j]<<"\t";
        }
        cout<<endl;
    }
}

void print_array(int array[lmax], int n){
    cout<<"Массив"<<endl;
    for (int i = 0; i < n; ++i) {
        cout<<array[i]<<"\t";
    }
    cout<<endl;
}

int main() {

    int n, m, a[lmax][lmax];
    int k, y[lmax];
    int length = 0, c[lmax];

    cout<<"Введите n и m"<<endl;
    cin>>n>>m;
    cout<<"Введите матрицу"<<endl;
    for(int i = 0; i<n; ++i){
        for (int j = 0; j < m; ++j) {
            cin>>a[i][j];
        }
    }

    cout<<"Введите k"<<endl;
    cin>>k;
    cout<<"Введите массив"<<endl;
    for (int i = 0; i < k; ++i) {
        cin>>y[i];
    }

    print_matrix(a, n, m);
    print_array(y, k);

    length = func(a, n, m, y, k, c);
    if (length){
        print_array(c, length);
    } else{
        cout<<"Результирующий массив пуст";
    }
    return 0;
}
