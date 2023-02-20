#include <stdio.h>

int zam(char *s)
{int f=0;
    for(;*s;s++)
        if (*s>='A'&&*s<='J')
    {f=1;*s=*s-'A'+0;
    }
    return 0;
}

int main()
{
    char a[] = "AB";
    zam(a);
    puts(a);
}