#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} *head, *temp, *newnode;
int main()
{
    int ch;
    head = 0;
    do
    {
        newnode = (struct node *)malloc(sizeof(struct node *));
        printf("Insert the element : \n");
        scanf("%d", &newnode->data);
        if (head == 0)
        {
            head = newnode;
            temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
            newnode->next = head;
        }
        printf("1: Continue\t; 2: Exit\n");
        scanf("%d", &ch);
    } while (ch == 1);

    temp = head;
    printf("Head : %p\n", head);
    do
    {
        printf("[%p | %d | %p]\n", temp, temp->data, temp->next);
        temp = temp->next;
    }while (temp != head);
    return 0;
}