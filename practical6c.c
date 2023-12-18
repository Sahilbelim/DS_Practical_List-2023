/*
Write a menu driven program to implement following operations on doubly linked list.1)Insert a
node at the front of the linked list. 2)Insert a node at the end of the linked list. 3)Delete a last node
of the linked list 4)Delete a node before specified position
*/
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the doubly linked list
struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

// Function to insert a node at the front of the doubly linked list
struct Node *insertAtFront(struct Node *head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL)
    {
        head->prev = newNode;
    }

    return newNode; // The new node becomes the new head
}

// Function to insert a node at the end of the doubly linked list
struct Node *insertAtEnd(struct Node *head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL)
    {
        // If the list is empty, the new node becomes the head
        newNode->prev = NULL;
        return newNode;
    }

    struct Node *current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }

    current->next = newNode;
    newNode->prev = current;
    return head;
}

// Function to delete the last node from the doubly linked list
struct Node *deleteLastNode(struct Node *head)
{
    if (head == NULL)
    {
        printf("The list is empty. Nothing to delete.\n");
        return NULL;
    }

    if (head->next == NULL)
    {
        // If there's only one node in the list, delete it
        free(head);
        return NULL;
    }

    struct Node *current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }

    current->prev->next = NULL;
    free(current);
    return head;
}

// Function to delete a node before a specified position (index)
struct Node *deleteBeforePosition(struct Node *head, int position)
{
    if (head == NULL || position <= 1)
    {
        printf("Cannot delete before position %d. Invalid operation.\n", position);
        return head;
    }

    struct Node *current = head;
    int count = 1;
    while (current->next != NULL && count < position - 1)
    {
        current = current->next;
        count++;
    }

    if (count < position - 1 || current->prev == NULL)
    {
        printf("Position %d is beyond the start of the list. Cannot delete.\n", position);
        return head;
    }

    struct Node *temp = current->prev;
    current->prev = temp->prev;
    free(temp);
    return head;
}

// Function to display the elements of the doubly linked list
void display(struct Node *head)
{
    struct Node *current = head;
    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main()
{
    struct Node *head = NULL; // Initialize an empty doubly linked list

    int choice;
    int data;
    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at End\n");
        printf("3. Delete Last Node\n");
        printf("4. Delete Before Position\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            // INSERT AT FRONT operation
            
            printf("Enter data to insert at the front: ");
            scanf("%d", &data);
            head = insertAtFront(head, data);
            break;

        case 2:
            // INSERT AT END operation
       
            printf("Enter data to insert at the end: ");
            scanf("%d", &data);
            head = insertAtEnd(head, data);
            break;

        case 3:
            // DELETE LAST NODE operation
            head = deleteLastNode(head);
            break;

        case 4:
            // DELETE BEFORE POSITION operation
        
            printf("Enter the position before which you want to delete: ");
            scanf("%d", &data);
            head = deleteBeforePosition(head, data);
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
