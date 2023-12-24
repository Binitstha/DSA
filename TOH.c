#include<stdio.h>
#include<conio.h>
int fact(int x)
{
    if(x==0||x==1)
    {
        return 1;
    }
    else
    {
        return x*fact(x-1);
    }
}
int main()
{
    int n;
    printf("Enter the number to find the factorial :");
    scanf("%d",&n);
    printf("factorial : %d",fact(n));
}