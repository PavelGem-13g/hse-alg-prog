#include <stdio.h>
#include <math.h>

#define lmax 10000

void print_array(int n, double array[]) {
    for (int i = 0; i < n; ++i) {
        printf("%lg ", array[i]);
    }
    printf("\n");
}


int main() {
    int n, k, start, end, temp, pos_i;
    double R[lmax], x, h, a, srznach, sum;
    {
        printf("Лабораторная работа №1\nВыполнил:Пашенцев Павел Владимирович\n");
        do {
            printf("Введите длину массива R в диапазоне от 2 до %d ", lmax);
            scanf("%d", &n);
        } while (!(1 < n && n < lmax));

        printf("Введите коэффициент x ");
        scanf("%lg", &x);

        printf("Введите коэффициент h ");
        scanf("%lg", &h);

        printf("Введите коэффициент a ");
        scanf("%lg", &a);
    }

    printf("Задача 1 \n");
    for (int i = 0; i < n; ++i) {
        R[i] = 1.25 * sin(3 * a * x - i * h);
    }
    print_array(n, R);

    printf("Задача 2 \n");
    int neg_i = -1;
    for (int i = 0; i < n; ++i) {
        if (R[i] < 0) {
            neg_i = i;
        }
    }
    if (neg_i != -1) {
        k = 0;
        for (int i = 0; i < neg_i; ++i) {
            if (R[i] < 0) {
                R[k] = R[i];
                ++k;
            }
        }
        for (int i = neg_i; i < n; ++i,++k) {
            R[k] = R[i];
        }
        neg_i -= n-k;
        printf("%d %d\n", n, k);
        if(n==k){
            printf("Нет элементов для удаления\n");
            printf("Задача 3 \n");
            printf("Нельзя посчитать среднее значение по условию задачи\n");
        } else{
            print_array(k, R);

            printf("Задача 3 \n");
            pos_i = -1;
            for (int i = 0; i < k; ++i) {
                pos_i = (R[i]>0)? i:pos_i;
            }
            if(pos_i!=-1){
                start = neg_i;
                end = pos_i;
                if(start>end){
                    temp = start;
                    start = end;
                    end = temp;
                }
                if (end-start > 0) {
                    sum = 0;
                    for (int i = start; i < end + 1; ++i) {
                        sum += R[i];
                    }
                    srznach = sum / (end-start+1);
                    printf("Среднее арифметическое %lg", srznach);
                } else {
                    printf("Нельзя посчитать среднее значение");
                }
            }
            else{
                printf("Нельзя найти последний положительный элемент\n");
                printf("Нельзя посчитать среднее значение по условию задачи\n");
            }
        }
    } else {
        printf("Нет отрицательных значений\n");
        printf("Задача 3 \n");
        printf("Нельзя посчитать среднее значение по условию задачи\n");
    }
    return 0;
}
