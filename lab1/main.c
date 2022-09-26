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
    int n, k, start, end, temp;
    double R[lmax], x, h, a, srznach, sum;
    {
        printf("Лабораторная работа №1\nВыполнил:Пашенцев Павел Владимирович\n");
        do {
            printf("Введите длину массива R в диапазоне от 2 до %d ", lmax);
            scanf("%d", &n);
        } while (!(2 < n && n < lmax));

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
    //поиск последнего отрицательного
    int neg_i = -1;
    for (int i = 0; i < n; ++i) {
        if (R[i] < 0) {
            neg_i = i;
        }
    }
    if (neg_i != -1) {
        //динамический сдвиг чисел
        int delta = 0;

        for (int i = 0; i < neg_i; ++i) {
            if (R[i] > 0) {
                ++delta;
            } else {
                R[i - delta] = R[i];
            }
        }
        if(delta==0){
            printf("Нет элементов для удаления");
        } else{
            // сдвиг оставшихся чисел
            for (int i = neg_i; i < n; ++i) {
                R[i - delta] = R[i];
            }
            neg_i -= delta;

            k = n - delta;
            print_array(k, R);

            printf("Задача 3 \n");

            int min_abs_i = 0;
            for (int i = 0; i < k; ++i) {
                min_abs_i = (fabs(R[min_abs_i])> fabs(R[i]))? i:min_abs_i;
            }

            start = neg_i;
            end = min_abs_i;
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


    } else {
        printf("Нет отрицательных значений");
    }


    return 0;
}
