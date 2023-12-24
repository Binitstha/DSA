#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
int main()
{
    int n, x;
    int a[n];
    int found = 0;
    printf("Enter the size of the array :");
    scanf("%d", &n);
    printf("Enter the element of the array :\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Enter the number to be searched :");
    scanf("%d", &x);

    for (int i = 0; i < n; i++)
    {
        if (x == a[i])
        {
            found = 1;
        }
    }
    if (found == 0)
    {
        printf("Searched number is not found");
    }
    else{
            printf("Searched number found : %d\n",x);
    }
}