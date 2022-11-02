#include <stdio.h>
#include <math.h>

int fack(int base);
int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    int A = fack(k)/fack(k-n);
    printf("%d", A);
    return 0;
}
int fack(int base){
    int result = 1;
    for(int i = 1; i<=base; i++){
        result *= i;
    }
    return result;
}