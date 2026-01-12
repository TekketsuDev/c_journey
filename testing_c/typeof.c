#include <stdio.h>

char foo(int x) { return (char)('A' + (x % 26)); }

int main(void)
{
    __typeof__(foo) *p = foo;   // p: char (*)(int)
    printf("%c\n", p(2));       // C
    return 0;
}

