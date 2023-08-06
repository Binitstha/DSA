#include <stdio.h>
#include <stdlib.h>
#define max 6
int queue[max];
int front = -1;
int rear = -1;
void enqueue(int element)
{
    if (front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
        queue[rear] = element;
    }
    else if ((rear + 1) % max == front)
    {
        printf("Queue is Full");
    }
    else
    {
        rear = (rear + 1) % max;
        queue[rear] = element;
    }
}
void dequeue()
{
    if ((front == -1) && (rear == -1))
    {
        printf("\n queue is underflow");
    }
    else if (front == rear)
    {
        printf("\n the queued element is; %d", queue[front]);
        front = -1;
        rear = -1;
    }
    else
    {
        printf("\n the queued element is %d", queue[front]);
        front = (front + 1) % max;
    }
}
void display()
{
    int i = front;
    if (front == -1 && rear == -1)
    {
        printf("\n Queue is empty");
    }
    else
    {
        printf("\n Elements in a queue are: ");
        while (i != rear)
        {
            printf("\n queue[%d]=%d", i, queue[i]);
            i = (i + 1) % max;
        }
        printf("\n queue[%d]=%d", i, queue[rear]);
    }
}
void main()
{
    int choice = 1, x;
    while (choice < 4 && choice != 0)
    {
        printf("1: Insert and Element\t");
        printf("2: Delete an Element\t");
        printf("3: Display the element\t");
        printf("\n Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("enter the element which is to be inserted:");
            scanf("%d", &x);
            enqueue(x);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        }
    }
}