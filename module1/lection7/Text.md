# Указатели

Пустть определена переменная типа указатель на величину некоторого типа, например:
1. int *ukaz;
2. char *uk;


Значением переменной типа указатель является адрес. С помощью операции взятии содержимого
по адресу (*ukaz) можно получить значение, хранящееся в той ячеке памяти, на которую
в данный момент показывает ukaz (переменная типа указатель).

int a[10];
можно обращаться так:
1. a+i
2. *uk

Выгоднее сохранять ОДИН указатель, чем ДВА индекса

# Определение индексов элементов матрицы, расположенных на, над и под главной и и прбочной диагонали

у главной диагонали совпадают оба индекса
