#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *ptr, n, i;
    printf("Enter the number of elements : \n");
    scanf("%d", &n);

    ptr = (int *)calloc(n, sizeof(int));

    if (ptr == NULL)
    {
        printf("Memory is not allocated : \n");
        exit(0);
    }
    else
    {
        printf("Memory is allocated : \n");
        printf("Elements are : \n");
        for (i = 0; i < n; i++)
        {
            ptr[i] = i + 1;
            printf("%d\n", ptr[i]);
        }
    }
    return 0;
}