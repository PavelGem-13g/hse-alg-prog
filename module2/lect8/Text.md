# Структура

Составной массив данных.

Объявление:
struct book
{
    char author[20], name [60];
    int year, price;
}

# Определим структурныю переменную kn1:
struct book kn1 = {"Иванов ", "физика", 2009б 175};
//book - тип 

Обращаемся к полям через точку. Действия аналогичные, как с обычными переменными.

Массивы структур
struct book kns[3];

# Вложенные структуры
Можно использовать структуры в структурах.

# Указатель на структуры
1. Проще
2. Меньше памяти

# Операции над структурами
Сравнение структур - сравниваются поля

1. Операция присоденения:
   1. Аналог * для указателей
2. Скобочки
   1. Чтобы использовать звездочку

# Передача информации о структурах в функцию

Структуру можно использовать в качестве формального параметра функции.

Можно передавать в качестве фактическго параметра элемент структуры или его адрес.

Можно передать ися массива структур в качестве фактического параметра (то есть адрес первого элемента массива)
