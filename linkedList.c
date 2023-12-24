#include <stdlib.h>
#include <conio.h>
#include <stdio.h>

struct node
{
    int data;
    struct node *next;
} *head = 0, *temp, *prev, *newNode;

int display()
{
    if (head == 0)
    {
        printf("List is empty \n");
    }
    else
    {
        temp = head;
        printf("\nHead = %p\n", head);
        while (temp != 0)
        {
            printf("[ %p | %d | %p ]\n\n", temp, temp->data, temp->next);
            temp = temp->next;
        }
    }
}
int CreateNode(int n)
{
    for (int i = 0; i < n; i++)
    {
        newNode = (struct node *)malloc(sizeof(struct node *));
        printf("Enter the data to be inserted :\n");
        scanf("%d", &newNode->data);
        newNode->next = 0;
        if (head == 0)
        {
            head = newNode;
            temp = newNode;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
    }
}
int insertAtBeginning()
{
    newNode = (struct node *)malloc(sizeof(struct node *));
    printf("Enter the element to insert at the beginning : \n");
    scanf("%d", &newNode->data);
    newNode->next = 0;
    if (head == 0)
    {
        head = newNode;
    }
    else
    {
        temp = head;
        head = newNode;
        newNode->next = temp;
    }
}
int insertAtlast()
{
    newNode = (struct node *)malloc(sizeof(struct node *));
    printf("Enter the element to insert at the beginning : \n");
    scanf("%d", &newNode->data);
    newNode->next = 0;
    if (head == 0)
    {
        head = newNode;
        temp = newNode;
    }
    else
    {
        temp = head;
        while (temp->next != 0)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

int deleteAtBeginning()
{
    if (head == 0 || head->next == 0)
    {
        printf("List is empty\n");
    }
    else
    {
        temp = head;
        printf("Deleted node -> [ %p | %d | %p ]\n", temp, temp->data, temp->next);
        head = temp->next;
        free(temp);
    }
}
int deleteAtLast()
{
    if (head == 0 || head->next == 0)
    {
        printf("The list is empty : \n");
    }
    else
    {
        temp = head;
        while (temp->next != 0)
        {
            prev = temp;
            temp = temp->next;
        }
        printf("Deleted node -> [ %p | %d | %p ]\n", temp, temp->data, temp->next);
        free(temp);
        prev->next = 0;
    }
}

int main()
{
    int ch = 1;
    int x;
    while (ch < 6)
    {
        printf("Enter the choice : \n");
        printf("0.Display\t1.Create nodes\t2.Insert at beginnig\t3.Insert at last\t4.Delete at beginnig\t5.Delete at last\n6.Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 0:
            display();
            break;
        case 1:
            printf("Enter the number of elements : \n");
            scanf("%d", &x);
            CreateNode(x);
            display();
            break;
        case 2:
            insertAtBeginning();
            break;
        case 3:
            insertAtlast();
            break;
        case 4:
            deleteAtBeginning();
            break;
        case 5:
            deleteAtLast();
            break;
        case 6:
            printf("Exiting....\n");
            exit(0);
        }
    }
}