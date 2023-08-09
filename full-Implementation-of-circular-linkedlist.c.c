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
} *head, *temp, *newnode, *last, *first;
int enqueue(int x)
{
    for (int i = 0; i < x; i++)
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
            last = temp;
        }
    }
}
int display()
{
    temp = head;
    if (head == 0)
    {
        printf("List is empty\n");
    }
    printf("Head = %p\n", head);
    do
    {
        printf("[%p | %d | %p]\n", temp, temp->data, temp->next);
        temp = temp->next;
    } while (temp != last->next);
    printf("last = %p : %d\n", last->next, last->data);
}
int deleteAtBegining()
{
    // last = temp;
    printf("last = %p : %d\n", last->next, last->data);
    if (head == 0)
    {
        printf("List is empty\n");
    }
    else
    {
        temp = head;
        head = head->next;
        free(temp);
    }
    last->next = head;
    printf("last = %p : %d\n", last->next, last->data);
    temp = head;
    printf("head = %p\n", head);
    do
    {
        printf("[%p | %d | %p]\n", temp, temp->data, temp->next);
        temp = temp->next;
    } while (temp != head);
    printf("last = %p : %d\n", last->next, last->data);
}
int deleteAtLast()
{
    printf("head = %p\n", head);
    temp = head;
    while (temp->next != last)
    {
        temp = temp->next;
    }
    temp->next = head;
    free(last);
    temp = head;
    do
    {
        printf("[%p | %d | %p]\n", temp, temp->data, temp->next);
        temp = temp->next;
    } while (temp->next != head);
    printf("[%p | %d | %p]\n", temp, temp->data, temp->next);
    last = temp;
    printf("last = %p : %d\n", last->next, last->data);
}
int insertAtLast()
{
    newnode = (struct node *)malloc(sizeof(struct node *));
    printf("last = %p : %d\n", last->next, last->data);
    printf("insert the element at last : \n");
    scanf("%d", &newnode->data);
    last->next = newnode;
    newnode->next = head;
    temp = head;
    do
    {
        printf("[%p | %d | %p]\n", temp, temp->data, temp->next);
        temp = temp->next;
    } while (temp->next != head);
    printf("[%p | %d | %p]\n", temp, temp->data, temp->next);
    last = temp;
}
int insertAtFirst()
{
    newnode = (struct node *)malloc(sizeof(struct node *));
    first = head;
    printf("Enter the element at last :\n");
    scanf("%d",&newnode->data);
    newnode->next = first;
    last->next = newnode;
    head = newnode;
    temp = head;
    printf(" head = [%p | %d | %p]\n",head ,head->data,head->next);
    do
    {
        printf("[%p | %d | %p]\n", temp, temp->data, temp->next);
        temp = temp->next;
    } while (temp != last);
    printf("[%p | %d | %p]\n", temp, temp->data, temp->next);
    last = temp;
}
int main()
{
    int n;
    int ch;
    do
    {
        if (ch != 1)
        {
            printf("1:Insert data\t 2:Display\t 3:Delete at begininig\t 4:insert at first\t 5:delete at last\t 6:insert at last\n");
        }
        printf("Enter the choice : \t 0 for exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
        {
            printf("Enter the no. of data : \n");
            scanf("%d", &n);
            enqueue(n);
            break;
        }
        case 2:
        {
            printf("the data are : \n");
            display();
            break;
        }
        case 3:
        {
            printf("after deletion at begining: \n");
            deleteAtBegining();
            break;
        }
        case 4:
        {
            printf("After insertion at first :\n");
            insertAtLast();
            break;
        }
        case 5:
        {
            printf("After deletion at last :\n");
            deleteAtLast();
            break;
        }
        case 6:
        {
            printf("After insertion at first :\n");
            insertAtFirst();
            break;
        }
        case 0:
        {
            exit(0);
        }
        }
    } while (ch);
}
