#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define size 5
int queue[size];
int front = -1;
int rear = -1;

int Enqueue()
{
    if (front == -1 && rear == -1)
    {
        rear = 0;
        front = 0;
        printf("Enter the element to enqueue : ");
        scanf("%d", &queue[rear]);
    }
    else if ((rear + 1) % size == front)
    {
        printf("Queue overflow \2\n");
    }
    else
    {
        rear = (rear + 1) % size;
        printf("Enter the element to enqueue : ");
        scanf("%d", &queue[rear]);
    }
}

int Dequeue()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue Empty\n");
    }
    else if (front == rear)
    {
        printf("Deqeued element is : %d\n", queue[front]);
        front = -1;
        rear = -1;
    }
    else
    {
        printf("Deqeued element is : %d\n", queue[front]);
        front = (front + 1) % size;
    }
}

int Display()
{
    if (rear == -1 && front == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        for (int i = front; i <= rear; i++)
        {
            printf("Queue[%d] | %d\n", i, queue[i]);
        }
    }
}

int main()
{
    int ch;
    while (1)
    {
        printf("enter the choice : ");
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
            printf("Exiting........\n");
            exit(0);
        }
    }
}