#include <stdio.h>
#include <ctype.h>

int main()
{
    char str[100], *s = str, *s1, *s2;
    int flag = 0;
    puts("Input one string");
    gets(str);
    if (!*str) puts("String is empty");
    else{
        while (*s){
        if (('a'<= *s && *s<='z')|| ('A'<= *s && *s<='Z')){
           s1 = s;
           char *t = s;
           while (*t && (('a'<= *t && *t<='z')|| ('A'<= *t && *t<='Z')))
           {
                ++t;
           }
           if ((t-s1)%2==0){
            for(int i = 0; i < t-s1; ++i){
                *(s1++) = *(s2++);
            }
           }
        }
        ++s;
        }

    }
}