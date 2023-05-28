#include <iostream>
#define lmax 1000

using namespace std;

void input(int *matrix, int *n, int *m){
    cout<<"Введите количество строк ";
    cin>>*n;
    cout<<"Введите количество столбцов ";
    cin>>*m;
    for (int i = 0; i < *n; ++i) {
        for (int j = 0; j < *m; ++j) {
            cin>>*(matrix+(*n)*i+j);
        }
    }

}

void output(int *matrix, int n, int m){
    cout<<"Матрица:"<<endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout<<*(matrix+(n)*i+j)<<"\t";
        }
        cout<<endl;
    }
}

int func(int *matrix, int n, int m){
    int maxi = 0, maxj = 0;
    int posi = -1, posj = -1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if(abs(*(matrix+n*maxi+maxj)) < abs(*(matrix+n*i+j))){
                maxi = i;
                maxj = j;
            }
            if(*(matrix+n*i+j)>0){
                posi = i;
                posj = j;
            }
        }
    }
    if ((maxi!=posi and maxj!=posj) and (posi!=-1 and posj!=-1)){
        int temp = *(matrix+n*maxi+maxj);
        *(matrix+n*maxi+maxj) = *(matrix+n*posi+posj);
        *(matrix+n*posi+posj) = temp;
        return 1;
    }
    return 0;
}

int main() {
    int matrix[lmax][lmax], n, m;

    input(*matrix, &n, &m);
    output(*matrix, n, m);

    if(func(*matrix, n, m)){
        output(*matrix, n, m);
    } else{
        cout<<"Матрица не изменилась";
    }


    return 0;
}
