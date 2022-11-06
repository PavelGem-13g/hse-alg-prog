#include <stdio.h>

#define lmax 1000

int input(int min, int max, char phrase[]){
    int result = 0, k = 0;
    do{
        printf(phrase);
        k = scanf("%d", result);
        while(getchar()!='\n');
    }while(k!=1 && (k<min || k>max));
    return result;
}
int input_matrix(){
        int n, m;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){

        }
    }
}

int main(){
    int b[lmax][lmax];

    return 0;
}