#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node *NODE;

NODE getNode()
{
    NODE temp;
    temp = (NODE)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        perror("Error");
        exit(0);
    }
    temp->next = NULL;
    return temp;
}

NODE createNode()
{
    NODE temp;
    temp = getNode();
    printf("Enter data: ");
    scanf("%d", &temp->data);
    return temp;
}

NODE insertNodeAtEnd(NODE head)
{
    NODE temp, cur;
    temp = createNode();
    temp->next = NULL;
    if (head == NULL)
    {
        return temp;
    }
    cur = head;
    while (cur->next != NULL)
    {
        cur = cur->next;
    }
    cur->next = temp;
    return head;
}

void displayList(NODE head)
{
    NODE cur;
    if (head == NULL)
    {
        printf("List empty\n");
        return;
    }
    printf("The elements are: ");
    cur = head;
    while (cur != NULL)
    {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

int main()
{
    NODE head = NULL;
    int choice;
     do
    {
        printf("Menu:\n1. Insert\n2. Display\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            head = insertNodeAtEnd(head);
            break;
        case 2:
            displayList(head);
            break;
        case 3:
            exit(0); // Exit the program
        default:
            printf("Invalid choice\n");
        }
    } while(1);

    return 0;
}
