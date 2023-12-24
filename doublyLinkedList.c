#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *prev;
    struct node *next;
    int data;
};
struct node *head;
void insertion_beginning();
void insertion_last();
void insertion_specified();
void deletion_beginning();
void deletion_last();
void deletion_specified();
void display();
void search();
void main()
{
    int choice = 0;
    while (choice != 9)
    {
        printf("\n*********Main Menu*********\n");
        printf("\nChoose one option from the following list ...\n");
        printf("\n===============================================\n");
        printf("\n1.Insert in begining\n2.Insert at last\n3.Insert at any random location\n4.Delete from Beginning\n5.Delete from last\n6.Delete the node after the given data\n7.Search\n8.Show\n9.Exit\n");
        printf("\nEnter your choice?\n");
        scanf("\n%d", &choice);
        switch (choice)
        {
        case 1:
            insertion_beginning();
            break;
        case 2:
            insertion_last();
            break;
        case 3:
            insertion_specified();
            break;
        case 4:
            deletion_beginning();
            break;
        case 5:
            deletion_last();
            break;
        case 6:
            deletion_specified();
            break;
        case 7:
            search();
            break;
        case 8:
            display();
            break;
        case 9:
            exit(0);
            break;
        default:
            printf("Please enter valid choice..");
        }
    }
}
void insertion_beginning()
{
    struct node *newNode;
    int item;
    newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL)
    {
        printf("\nOVERFLOW");
    }
    else
    {
        printf("\nEnter Item value");
        scanf("%d", &item);

        if (head == NULL)
        {
            newNode->next = NULL;
            newNode->prev = NULL;
            newNode->data = item;
            head = newNode;
        }
        else
        {
            newNode->data = item;
            newNode->prev = NULL;
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        printf("\nNode inserted\n");
    }
}
void insertion_last()
{
    struct node *newNode, *temp;
    int item;
    newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL)
    {
        printf("\nOVERFLOW");
    }
    else
    {
        printf("\nEnter value");
        scanf("%d", &item);
        newNode->data = item;
        if (head == NULL)
        {
            newNode->next = NULL;
            newNode->prev = NULL;
            head = newNode;
        }
        else
        {
            temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
            newNode->next = NULL;
        }
    }
    printf("\nnode inserted\n");
}
void insertion_specified()
{
    struct node *newNode, *temp;
    int item, loc, i;
    newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL)
    {
        printf("\n OVERFLOW");
    }
    else
    {
        temp = head;
        printf("Enter the location");
        scanf("%d", &loc);
        for (i = 0; i < loc; i++)
        {
            temp = temp->next;
            if (temp == NULL)
            {
                printf("\n There are less than %d elements", loc);
                return;
            }
        }
        printf("Enter value");
        scanf("%d", &item);
        newNode->data = item;
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next = newNode;
        temp->next->prev = newNode;
        printf("\nnode inserted\n");
    }
}
void deletion_beginning()
{
    struct node *temp;
    if (head == NULL)
    {
        printf("\n UNDERFLOW");
    }
    else if (head->next == NULL)
    {
        head = NULL;
        free(head);
        printf("\nnode deleted\n");
    }
    else
    {
        temp = head;
        head = head->next;
        head->prev = NULL;
        free(temp);
        printf("\nnode deleted\n");
    }
}
void deletion_last()
{
    struct node *temp;
    if (head == NULL)
    {
        printf("\n UNDERFLOW");
    }
    else if (head->next == NULL)
    {
        head = NULL;
        free(head);
        printf("\nnode deleted\n");
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->prev->next = NULL;
        free(temp);
        printf("\nnode deleted\n");
    }
}
void deletion_specified()
{
    struct node *prevTemp, *temp;
    int val;
    printf("\n Enter the data after which the node is to be deleted : ");
    scanf("%d", &val);
    prevTemp = head;
    while (prevTemp->data != val)
        prevTemp = prevTemp->next;
    if (prevTemp->next == NULL)
    {
        printf("\nCan't delete\n");
    }
    else if (prevTemp->next->next == NULL)
    {
        prevTemp->next = NULL;
    }
    else
    {
        temp = prevTemp->next;
        prevTemp->next = temp->next;
        temp->next->prev = prevTemp;
        free(temp);
        printf("\nnode deleted\n");
    }
}
void display()
{
    struct node *newNode;
    printf("\n printing values...\n");
    newNode = head;
    while (newNode != NULL)
    {
        printf("%d\n", newNode->data);
        newNode = newNode->next;
    }
}
void search()
{
    struct node *newNode;
    int item, i = 0, flag;
    newNode = head;
    if (newNode == NULL)
    {
        printf("\nEmpty List\n");
    }
    else
    {
        printf("\nEnter item which you want to search?\n");
        scanf("%d", &item);
        while (newNode != NULL)
        {
            if (newNode->data == item)
            {
                printf("\nitem found at location %d ", i + 1);
                flag = 0;
                break;
            }
            else
            {
                flag = 1;
            }
            i++;
            newNode = newNode->next;
        }
        if (flag == 1)
        {
            printf("\nItem not found\n");
        }
    }
}