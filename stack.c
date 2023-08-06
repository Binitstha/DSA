#include <stdio.h>
int stack[50], choice = 0, i, j, top = -1;
int n;
int push();
int pop();
int show();
int main()
{
    printf("Enter the element of stack : \n ");
    scanf("%d", &n);
    while (choice != 5)
    {
        printf("Enter the choice : \n");
        printf("1=push\n2=pop\n3=show\n4=exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            push();
            break;
        }
        case 2:
        {
            pop();
            break;
        }
        case 3:
        {
            show();
            break;
        }
        case 4:
        {
            printf("Exiting.........\n");
            break;
        }
        default:
            printf("Enter the valid choice : \n");
            break;
        };
    }
    return 0;
}
int push()
{
    int val;
    if (top == n)
    {
        printf("stack overflow : \n");
    }
    else
    {
        printf("Enter the value : \n");
        scanf("%d", &val);
        top += 1;
        stack[top] = val;
    }
}
int pop()
{
    if (top == -1)
    {
        printf("stack underflow\n");
    }
    else
    {
        top -= 1;
    }
}
int show()
{
    for (i = 0; i < top; i++)
    {
        printf("%d\n", stack[i]);
    }
    if (top = -1)
    {
        printf("stack underflow : \n");
    }
}
