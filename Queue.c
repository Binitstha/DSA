#include <stdio.h>
#define size 5
int queue[size];
int front = -1;
int rear = -1;
int enqueue(int a)
{
    if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = a;
    }
    else if (rear == size - 1)
    {
        printf("Queue is full\e");
    }
    else
    {
        rear++;
        queue[rear] = a;
    }
}
int dequeue()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue is empty\n");
    }
    else if (rear == front)
    {
        printf("Dequeued item is : [%d] \n", queue[front]);
        rear = -1;
        front = -1;
    }
    else
    {
        printf("Dequeued item is : [%d] \n", queue[front]);
        front++;
    }
}
int display()
{
    if (front > rear)
    {
        printf("Queue is empty");
    }
    else
    {
        for (int i = front; i <= rear; i++)
        {
            printf("[%d] : [%d]\n", i, queue[i]);
            // rear++;
        }
    }
}
int main()
{
    int ch;
    int x;
    printf("1:Enqueue\t , 2:Dequeue\tt ,3:Display\n");
    while (ch < 4)
    {
        printf("Enter the choice : \n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
        {
            printf("Enter the element :");
            scanf("%d", &x);
            enqueue(x);
            break;
        }
        case 2:
        {
            dequeue();
            break;
        }
        case 3:
        {
            display();
            break;
        }
        }
    }
}