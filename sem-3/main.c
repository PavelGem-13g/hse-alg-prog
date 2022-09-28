#include <stdio.h>

#define lmax 20

int main() {
    int na;
    scanf("%d", &na);
    int a[lmax], b[lmax];
    int nb = 0;
    for (int i = 0; i < na; ++i) {
        int j = 0;
        while (j <= nb && a[i] != b[j]) {
            ++j;
        }
        if (j > nb) {
            ++nb;
            b[nb] = a[i];
        }
    }
    for (int i = 0; i < nb; ++i) {
        printf("%d ", b[i]);
    }
    return 0;
}
