/*
Write a menu driven program to implement following operations on circular singly linked
list.1)Insert a node at the end of the linked list. 2)Insert a node before specified position. 3)Delete
first node in the linked list. 4)Delete a node after specified position
*/
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the circular singly linked list
struct Node
{
    int data;
    struct Node *next;
};

// Function to insert a node at the end of the circular singly linked list
struct Node *insertAtEnd(struct Node *head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;

    if (head == NULL)
    {
        // If the list is empty, make the new node point to itself
        newNode->next = newNode;
        return newNode;
    }

    struct Node *current = head;
    while (current->next != head)
    {
        current = current->next;
    }

    current->next = newNode;
    newNode->next = head; // Make the new node point back to the head
    return head;
}

// Function to insert a node before a specified position (index) in the circular singly linked list
struct Node *insertBeforePosition(struct Node *head, int position, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;

    if (head == NULL)
    {
        // If the list is empty, make the new node point to itself
        newNode->next = newNode;
        return newNode;
    }

    if (position <= 1)
    {
        // Insert at the beginning
        struct Node *current = head;
        while (current->next != head)
        {
            current = current->next;
        }

        current->next = newNode;
        newNode->next = head;
        return newNode;
    }

    struct Node *current = head;
    int count = 1;
    while (count < position - 1)
    {
        current = current->next;
        count++;
    }

    newNode->next = current->next;
    current->next = newNode;
    return head;
}

// Function to delete the first node from the circular singly linked list
struct Node *deleteFirstNode(struct Node *head)
{
    if (head == NULL)
    {
        printf("The list is empty. Nothing to delete.\n");
        return NULL;
    }

    if (head->next == head)
    {
        // If there's only one node in the list, delete it
        free(head);
        return NULL;
    }

    struct Node *current = head;
    while (current->next != head)
    {
        current = current->next;
    }

    current->next = head->next;
    free(head);
    return current->next;
}

// Function to delete a node after a specified position (index) in the circular singly linked list
struct Node *deleteAfterPosition(struct Node *head, int position)
{
    if (head == NULL || position < 1)
    {
        printf("Cannot delete after position %d. Invalid operation.\n", position);
        return head;
    }

    struct Node *current = head;
    int count = 1;
    while (count < position && current->next != head)
    {
        current = current->next;
        count++;
    }

    if (count < position || current->next == head)
    {
        printf("Position %d is beyond the end of the list. Cannot delete.\n", position);
        return head;
    }

    struct Node *temp = current->next;
    current->next = temp->next;
    free(temp);
    return head;
}

// Function to display the elements of the circular singly linked list
void display(struct Node *head)
{
    if (head == NULL)
    {
        printf("The list is empty.\n");
        return;
    }

    struct Node *current = head;
    do
    {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != head);

    printf("Head\n");
}

int main()
{
    struct Node *head = NULL; // Initialize an empty circular singly linked list

    int choice;
    int data1, data2;

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Insert at End\n");
        printf("2. Insert Before Position\n");
        printf("3. Delete First Node\n");
        printf("4. Delete After Position\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            // INSERT AT END operation
           
            printf("Enter data to insert at the end: ");
            scanf("%d", &data1);
            head = insertAtEnd(head, data1);
            break;

        case 2:
            // INSERT BEFORE POSITION operation
          
            printf("Enter the position before which you want to insert: ");
            scanf("%d", &data1);
            printf("Enter data to insert: ");
            scanf("%d", &data2);
            head = insertBeforePosition(head, data1, data2);
            break;

        case 3:
            // DELETE FIRST NODE operation
            head = deleteFirstNode(head);
            break;

        case 4:
            // DELETE AFTER POSITION operation
           
            printf("Enter the position after which you want to delete: ");
            scanf("%d", &data1);
            head = deleteAfterPosition(head, data1);
            break;

        case 5:
            // DISPLAY operation
            display(head);
            break;

        case 6:
            // Exit the program
            printf("Exiting the program.\n");
            return 0;

        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
