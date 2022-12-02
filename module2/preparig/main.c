#include <stdio.h>
#define lmax 1000

void func(int a[lmax][lmax]){
    a[1][1] = 7;
}

int main() {
    int a[lmax][lmax];
    func(a);
    printf("%d",a[1][1]);
}
