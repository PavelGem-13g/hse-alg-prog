#include <stdio.h>
#include <limits.h>

#define lmax 100


int count_contains(int a, int z) {
    int result = 0, temp = 0;
    while (a > 0) {
        temp = a % 10;
        if (z == temp) {
            ++result;
        }
        a /= 10;
    }
    return result;
}


void prit_matrix(int *array, int x, int y) {
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            printf("%d ", *array++);
        }
        printf("\n");
    }
    printf("\n");
}


void print_string(char phrase[]) {
    int i = 0;
    while (phrase[i] != '\0') {
        printf("%c", phrase[i]);
        ++i;
    }
    printf("\n");
}


int get_value(int min, int max, char phrase[]) {
    int result = 0;
    int count = 0;
    do {
        print_string(phrase);
        count = scanf("%d", &result);
        while (getchar() != '\n');
    } while (count != 1 || (min > result || result > max));
    return result;
}


int main() {
    int n, m, x, y, p, q, B[lmax][lmax],A[lmax][lmax], C[lmax][lmax], max_i = 0, max_j = 0;//почему-то компилятор не даёт поставить больше значения
    n = get_value(2, INT_MAX, "Введите число n");
    m = get_value(2, INT_MAX, "Введите число m");
    x = get_value(2, INT_MAX, "Введите число x");
    y = get_value(2, INT_MAX, "Введите число y");

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            A[i][j] = get_value(INT_MIN,INT_MAX,"Введите элемент матрицы A");
        }
    }

    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            B[i][j] = get_value(INT_MIN,INT_MAX,"Введите элемент матрицы B");
        }
    }

    //prit_matrix(*A,n,m);
    p = (n>x)? n:x;
    q = (m>y)? m:y;
    for (int i = 0; i < p; ++i) {
        for (int j = 0; j < q; ++j) {
            if(i<n && i<x && j<m && j<y){
                C[i][j] = A[i][j] +B [i][j];
            } else {
                if(i < n  && j < m ){//&& i >= x && j >= y
                    C[i][j] = A[i][j];
                } else {
                    if(i < x &&  j < y){//i >= n && j >= m &&
                        C[i][j] = B[i][j];
                    } else{
                        C[i][j] = 0;
                    }
                }
            }
            if(C[max_i][max_j]<C[i][j]){
                max_i = i;
                max_j = j;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if(A[i][j]==C[max_i][max_j]){
                C[max_i][max_j] = 0;
                break;
            }
        }
    }
    for (int i = 0; i < p; ++i) {
        for (int j = 0; j < q; ++j) {
            printf("%d \t", C[i][j]);
        }
        printf("\n");
    }
    return 0;
}
