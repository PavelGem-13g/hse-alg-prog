# Массив
Пронумерованная поименнованная совокупность данных одного типа. Массив имеет имя и тип элементов

Нумерация в C начинается с 0. Размер массива задается при инициализации

Обращение - A[i]


# Массив и матрицы
# Массив
Имя массива - указатель на его первый элемент, те записи mas и &mas[0] эквивалентны.

Взять i-ый элемент:
1. mas[i] 
2. *(mas+i) - разадресация


## Матрица
Нумерация также начинается с нуля

Обращение к значению:
1. b[i][j]
2. *(b[i]+j)
3. *(*(b+i)+j) - разадресация

Матрица - массив массивов. Название массива - указатель на первый массив


# Алгоритмы с досрочным выходом из цикла
В таких задачах ВСЕГДА используется целый тип (лучше сравнивается)

Досрочный выход из цикла подразумевает, что цикл может закончиться раньше, чем будет просмотрен весь массив

Для досрочного выхода используются ВСЕ циклы (чаще с предусловием и постусловием)

Присутствие - точное сравнение, поэтому int 