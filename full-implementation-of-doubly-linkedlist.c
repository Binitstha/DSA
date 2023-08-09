#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
} *head, *temp, *newnode, *first, *last;

int enqueue(int n)
{
    for (int i = 0; i < n; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node *));

        printf("Insert the element of list : \n");
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
            newnode->prev = temp;
            temp->next = newnode;
            temp = newnode;
            last = temp;
        }
    }
}
int display()
{
    if (head == 0)
    {
        printf("List is empty\n");
    }
    else
    {
        temp = head;
        printf("Head = %p\n", head);
        while (temp != 0)
        {
            printf("[prev = %p | current = %p | data = %d | next = %p]\n", temp->prev, temp, temp->data, temp->next);
            temp = temp->next;
        }
    }
}
int insertAtBegining()
{
    first = head;
    newnode = (struct node *)malloc(sizeof(struct node *));

    printf("Insert the element of list at begining :\n");
    scanf("%d", &newnode->data);

    newnode->prev = 0;
    first->prev = newnode;
    newnode->next = first;
    head = newnode;

    temp = head;
    printf("Head = %p\n", head);
    while (temp != 0)
    {
        printf("[prev = %p | current = %p | data = %d | next = %p]\n", temp->prev, temp, temp->data, temp->next);
        temp = temp->next;
    }
}

int insertAtLast()
{
    newnode = (struct node *)malloc(sizeof(struct node *));

    printf("Insert the element of list at last :\n");
    scanf("%d", &newnode->data);

    newnode->next = 0;
    last->next = newnode;
    newnode->prev = last;
    last = newnode;

    temp = head;
    printf("Head = %p\n", head);
    while (temp != 0)
    {
        printf("[prev = %p | current = %p | data = %d | next = %p]\n", temp->prev, temp, temp->data, temp->next);
        temp = temp->next;
    }
}
int deleteAtBegining()
{
    if (head == 0)
    {
        printf("List is empty :\n");
    }
    else
    {
        first = head;
        head = head->next;
        free(first);
        first = head;

        temp = head;
        printf("Head = %p\n", head);
        while (temp != 0)
        {
            printf("[prev = %p | current = %p | data = %d | next = %p]\n", temp->prev, temp, temp->data, temp->next);
            temp = temp->next;
        }
    }
}
int deleteAtLast()
{
    if (head->next == 0)
    {
        printf("List is empty :\n");
    }
    else
    {
        temp = last;
        last = last->prev;
        last->next = 0;
        free(temp);

        temp = head;
        printf("Head = %p\n", head);
        while (temp != 0)
        {
            printf("[prev = %p | current = %p | data = %d | next = %p]\n", temp->prev, temp, temp->data, temp->next);
            temp = temp->next;
        }
    }
}

int main()
{
    int ch;
    int x;
    int head = 0;
    do
    {
        if (ch != 1)
        {
            printf("1:Enqueue\t 2:Dequeue\t 3:Insert at begining\t 4:Insert at last\t 5: Delete at begining\t 6:Delete at last\t 0:Exit\n ");
        }
        printf("Enter the choice : \n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
        {
            printf("Enter the element of Linked list :\n");
            scanf("%d", &x);
            enqueue(x);
            break;
        }
        case 2:
        {
            display();
            break;
        }
        case 3:
        {
            insertAtBegining();
            break;
        }
        case 4:
        {
            insertAtLast();
            break;
        }
        case 5:
        {
            deleteAtBegining();
            break;
        }
        case 6:
        {
            deleteAtLast();
            break;
        }
        case 0:
        {
            exit(0);
        }
        }
    } while (ch);
}