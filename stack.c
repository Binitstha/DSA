#include <stdio.h>
#include <conio.h>
#include<stdlib.h>
#define size 5
int a[size];
int top = -1;
int enqueue()
{
    if (top == size)
    {
        printf("Stack overflow\n");
    }
    else
    {
        printf("Enter the element of the stack : \n");
        for (int i = 0; i < size; i++)
        {
            scanf("%d", &a[i]);
            top++;
        }
    }
}

int dequeue()
{
    if (top == -1)
    {
        printf("Stack underflow\n");
    }
    else
    {
        printf("Dequeued item is %d\n", a[top]);
        top--;
    }
}
int display()
{
    if (top == -1)
    {
        printf("Stack underflow\n");
    }
    else
    {
        printf("Stack element are : \n");
        for (int i = top; i >= 0; i--)
        {
            printf("%d | %d\n", i, a[i]);
        }
    }
}
int main()
{
    int ch = 1;
    while (ch < 5)
    {
        printf("\n1.Enqueue\t2.Dequeue\t3.Display\t4.Exit\n");
        printf("Enter the choice : \n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting.....\n");
            exit(0);
        }
    }
}