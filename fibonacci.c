#include <stdio.h>
#include <conio.h>
int fibo(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else if(n==1)
    {
        return 1;
    }
    else
    {
        return fibo(n - 2) + fibo(n - 1);
    }
}
int main()
{
    int x;
    printf("Enter the number of series :");
    scanf("%d", &x);
    for (int i = 0; i < x; i++)
    {
        printf("%d\t", fibo(i));
    }
}