#include<stdio.h>

int main()
{
    int n;
    int flag = 0;

    scanf("%d", &n);
    for(int i=1; i<n/2; i++)
    {
        if(i%2 == 0)
        {
            printf("The number is not prime");
            flag = 1;
            break;
        }
    }

    if(!flag)
        printf("The number is prime");
    return 0;
}