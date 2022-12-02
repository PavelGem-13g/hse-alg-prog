#include <stdio.h>
#include <strings.h>
#include <ctype.h>

int main()
{
    int *a = NULL;
    if(!a){
        printf("yes");
    } else{
        printf("no");
    }

    //printf("%d", isdigit('\0'));
/*    char str1[] = "Быть или не быть";
    char str2[10];
    //strncpy(str2, str1, 8);                   // скопировать 8 байт строки str1 в строку str2
                          // добавить в конец строки символ конца строки
    printf(str2);*/
    return 0;
}