#include <stdio.h>
#include <conio.h>

int fact(int c, int a)
{
    if (c == 0)
        return a;
    else
        return fact(c - 1, c * a);
}

int main()
{
    int x;
    printf("Enter the number to find the factorial : \n");
    scanf("%d",&x);
    // printf("Factorial of %d = %d\n",x,factorial(x));
    printf("%d", fact(x, 1));
}