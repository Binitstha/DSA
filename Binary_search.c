#include <stdio.h>
#include <conio.h>
int main()
{
    int n, a[10],search;
    printf("Enter the number of element :");
    scanf("%d", &n);

    printf("Enter the element :\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Enter the element to be searched :");
    scanf("%d",&search);

    int first = 0;
    int last = n-1;
    int middle = (last+first)/2;

    while(first <= last)
    {
        if(a[middle] < search)
        {
            first = middle +1;
        }
        else if(a[middle]== search)
        {
            printf("%d is found in %d position",search,middle+1);
            break;
        }
        else{
            last = middle-1;
        }
        middle = (first + last)/2;
    }
    if(first > last)
    {
        printf("Not found");
    }
}