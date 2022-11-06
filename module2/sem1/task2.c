#include <stdio.h>

#define lmax 1000

int main(){
    int n, a[lmax], b[lmax];
    scanf("%d", &n);
    for(int *i = a;i < a + n;++i){
        scanf("%d", i);
    }
    int k = 0;
    int number;
    for(int *i = a; i < a + n; ++i){
        k = 0;
        for(int *j = a; j < a + n; ++j){
            //printf("%d %d %d \n", *i, *j, k);
            if(i!=j && *i==*j){
                k++;
            }
            if (k>1){
                break;
            }
        }
        if(k==1){
            b[number] = *i;
            ++number;
        }
    }
    for(int *i = b; i < b + number;++i){
        printf("%d ", *i);
    }
    return 0;
}