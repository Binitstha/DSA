#include <stdio.h>
#include <stdlib.h>
int main()
{
    struct node
    {
        int data;
        struct node *next;
        struct node *prev;
    } *head, *temp, *newnode;
    head = 0;
    int ch;
    do
    {
        newnode = (struct node *)malloc(sizeof(struct node *));
        printf("Insert the element : \n");
        scanf("%d", &newnode->data);
        newnode->prev = 0;
        newnode->next = 0;
        if (head == 0)
        {
            head = newnode;
            temp = newnode;
        }
        else
        {
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
        }
        printf("1: Continue\t, 2: Exti and print\n");
        scanf("%d", &ch);
    } while (ch == 1);
    temp = head;
    printf("Head = %p\n",head);
    while (temp != 0)
    {
        printf("[%p | %d[%p] | %p]\n", temp->prev, temp->data,temp, temp->next);
        temp = temp->next;
    }
    return 0;
}