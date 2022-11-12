#include<stdio.h>

int main()
{
    int a = 10;
    int b = 20;

    // Original Values
    printf("%d ", a);
    printf("%d\n",b);

    int c = a;
    a = b;
    b = c;
    
    // Swap
    printf("%d ", a);
    printf("%d\n",b);
    return 0;
}
