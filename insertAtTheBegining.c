//  Circular linked list
// Write an algorithm and implementation C- program:
//  Insert at the beginning and end
//  Delete at the beginning and end
// ===================================
//  Doubly Linked List:
// Write an algorithm and implementation using c
//  Insert at the beginning and end
//  Delete at the beginning and end

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *head, *temp, *newnode;
int enqueue()
{
    newnode = (struct node *)malloc(sizeof(struct node *));
    printf("Insert the element : \n");
    scanf("%d", &newnode->data);
    newnode->next = 0;
    if (head == 0)
    {
        head = newnode;
        temp = newnode;
    }
    else
    {
        temp->next = newnode;
        temp = newnode;
    }
}
int display()
{
    temp = head;
    printf("Head = %p\n", head);
    while (temp != 0)
    {
        printf("[%p | %d | %p]\n", temp, temp->data, temp->next);
        temp = temp->next;
    }
}
int dequeue()
{
    if (head == 0)
    {
        printf("Linked list is empty \n");
    }
    else{
        printf("dequeueed item is : %d\n",temp->data);
        temp = head;
        while(temp->next != 0)
        {
            printf("[%p | %d | %p]",temp,temp->data,temp->next);
            temp= temp->next;
        }
    }
}
int main()
{
    int ch;
    do
    {
        printf("Enter the choice : \t 0 for exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
        {
            enqueue();
            break;
        }
        case 2:
        {
            display();
            break;
        }
        case 3:
        {
            dequeue();
            break;
        }
        case 0:
        {
            exit(0);
        }
        }
    } while (ch);
}