#include <stdio.h>
#include <stdlib.h>
int main()
{
    struct node
    {
        int data;
        struct node *next;
    } *head, *temp, *newnode;
    int ch;
    head = 0;
    do
    {
        newnode = (struct node *)malloc(sizeof(struct node *));
        printf("insert the element : ");
        scanf("%d",&newnode->data);
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
        printf("1 : Continue\t 2: Exit\n");
        scanf("%d", &ch);
    } while (ch == 1);
    temp = head;
    printf("Head = %p\n", head);
    while (temp != 0)
    {
        printf("[%d | %p]\n", temp->data, temp->next);
        temp = temp->next;
    }
    return 0;
}