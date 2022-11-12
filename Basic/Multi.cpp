#include<stdio.h>

int main()
{
    //n x 1 = 1 * n
    //n x 2 = 2 * n

    int n;
    printf("Enter a number \n");
    scanf("%d", &n);

    int i = 1;
    while(false)
    {
        printf("%d X %d = %d\n",n, i, n * i);
        i++;
    }
    return 0;
}