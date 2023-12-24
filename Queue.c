#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define size 5
int front = -1;
int rear = -1;
int Queue[size];
int Enqueue()
{
    printf("Enter the element to insert in the Queue : \n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &Queue[i]);
        front = 0;
        rear++;
    }
}
int Dequeue()
{
    if (rear == -1 && front == -1)
    {
        printf("Queue underflow\n");
    }
    else if (rear == front)
    {
        printf("Dequeued item is %d\n", Queue[front]);
        rear = -1;
        front = -1;
    }
    else
    {
        printf("Dequeued item is %d\n", Queue[front]);
        front++;
    }
}
int Display()
{
    if (rear == -1 && front == -1)
    {
        printf("Queue underflow\n");
    }
    else
    {
        printf("Element of the queue : \n");
        for (int i = front; i <= rear; i++)
        {
            printf("%d | %d\n", i, Queue[i]);
        }
    }
}
int main()
{
    int ch = 1;
    while (ch < 5)
    {
        printf("Enter the choice : \n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            Enqueue();
            break;
        case 2:
            Dequeue();
            break;
        case 3:
            Display();
            break;
        case 4:
            printf("Exiting.......\n");
            exit(0);
        }
    }
}