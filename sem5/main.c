#include <stdio.h>
#include <limits.h>

#define lmax SHRT_MAX


int main() {
    int a[lmax], b[lmax], c[lmax];
    int an, bn;
    scanf("%d %d",&an,&bn);

    for (int *i = a; i < a+an; ++i) {
        scanf("%d", i);
    }

    for (int *i = b; i < b+ bn; ++i) {
        scanf("%d", i);
    }

    int k = 0;
    int flag = 0;
    for (int *i = a; i < a + an; ++i) {
        for (int *j = i+1; j < a + an; ++j) {
            if (i==j){
                flag = 0;
                for (int *l = b; l < b + bn; ++l) {
                    if(*i==*l){
                        flag = 1;
                        break;
                    }
                }
                if(!flag){
                    printf("%d 1", *i);
                    c[k] = *i;
                    ++k;
                    break;
                }
            }
        }
    }
    printf("\n");
    for (int i = 0; i < k; ++i) {
        printf("%d ", c[i]);
    }
    return 0;
}
// 7 4
// 1 2 1 2 2 3 4
// 1 3 0 -5
