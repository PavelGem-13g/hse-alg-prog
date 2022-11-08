# Двумерные массивы. Ввод и вывод
void vv_matr(int a[][10], int *n, int *m)// или int(*a)[10]
{// передаём массив указателей на строки, n и m - по адресу
    int i,j;
    scanf("%d", n);
    scanf("%d", m);
    for (i = 0; i<*n;i++){
        for (j = 0; j<*m;j++){
            scanf(%d, a[i]+j);
        }
    }
}
//передаём n и m по значениию
void vivod(int a[][10], int n m int m)
{
    int i,j;

    for (i = 0; i< n;i++){
        for (j = 0; j<*m;j++){
            printf(%d, a[i][j]);
        }
    }
}


Оператор return в языке C обеспечивает досрочный выход из функции.

Бинарный поиск
// бинарный поиск в отсортированном массиве
int search(int a[], int n, int number)
{
    int left, right, middle;
    left = 0;
    right = n-1;
    middle = (left+right)/2;
    while(left<=right){
        if (a[middle] == number) return middle;
         middle = (left+right)/2;
    }
    return 0;
}