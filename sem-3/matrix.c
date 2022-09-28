#include <stdio.h>
#include <limits.h>

#define lmax 20

int matrix() {
    int nb, na, ma;
    int b[lmax], a[lmax][lmax];
    int min = INT_MAX-1;
    short flag = 0;
    scanf("%d %d %d", &na, &ma, &nb);

    for (int i = 0; i < na; ++i) {
        for (int j = 0; j < ma; ++j) {
            scanf("%d ", &a[i][j]);
        }
    }

    for (int i = 0; i < nb; ++i) {
        scanf("%d ", &b[i]);
    }

    for (int i = 0; i < na; ++i) {
        for (int j = 0; j < ma; ++j) {
            int k = 0;
            while (k<=nb && (a[i][j]!=b[k])){
                ++k;
            }
            if (k>nb && a[i][j]){
                min = a[i][j];
                flag = 1;
            }
        }
    }
    if(flag){
        printf("%d", &flag);
    } else{
        printf("Нет минимума");
    }
    return 0;