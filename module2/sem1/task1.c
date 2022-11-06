#include <stdio.h>
#include <math.h>

int fack(int base);
int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    int A = fack(k)/fack(k-n);
    printf("%d \n", A);
    return 0;
}
int fack(int base){
    if (base==0){
        return 1;
    }
    return base*fack(base-1);
}