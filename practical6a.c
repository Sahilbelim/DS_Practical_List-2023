/*
1)Insert a node at the front of the linked list 2)Insert a node at the end of the linked list 3)Insert a node such that linked list is in ascending order. (according to info. field) 4)Delete a first node of the linked list. 5)Delete a node before specified position6)Delete a node after specified position
*/
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the singly linked list
struct Node
{
    int data;
    struct Node *next;
};

// Function to insert a node at the front of the linked list
struct Node *insertAtFront(struct Node *head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    return newNode; // The new node becomes the new head
}

// Function to insert a node at the end of the linked list
struct Node *insertAtEnd(struct Node *head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL)
    {
        // If the list is empty, the new node becomes the head
        return newNode;
    }

    struct Node *current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

// Function to insert a node in ascending order
struct Node *insertInAscendingOrder(struct Node *head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL || data < head->data)
    {
        // If the list is empty or the new node data is smaller than the head's data
        // the new node becomes the new head
        newNode->next = head;
        return newNode;
    }

    struct Node *current = head;
    while (current->next != NULL && current->next->data < data)
    {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
    return head;
}

// Function to delete the first node from the linked list
struct Node *deleteFirstNode(struct Node *head)
{
    if (head == NULL)
    {
        printf("The list is empty. Nothing to delete.\n");
        return NULL;
    }

    struct Node *temp = head;
    head = head->next;
    free(temp);
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

    if (count < position - 1 || current->next == NULL)
    {
        printf("Position %d is beyond the end of the list. Cannot delete.\n", position);
        return head;
    }

    struct Node *temp = current->next;
    current->next = temp->next;
    free(temp);
    return head;
}

// Function to delete a node after a specified position (index)
struct Node *deleteAfterPosition(struct Node *head, int position)
{
    if (head == NULL)
    {
        printf("The list is empty. Nothing to delete.\n");
        return NULL;
    }

    if (position <= 0)
    {
        printf("Invalid position %d. Cannot delete.\n", position);
        return head;
    }

    struct Node *current = head;
    int count = 1;
    while (current != NULL && count < position)
    {
        current = current->next;
        count++;
    }

    if (count < position || current == NULL || current->next == NULL)
    {
        printf("Position %d is beyond the end of the list. Cannot delete.\n", position);
        return head;
    }

    struct Node *temp = current->next;
    current->next = temp->next;
    free(temp);
    return head;
}

// Function to display the elements of the linked list
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
    struct Node *head = NULL; // Initialize an empty linked list

    int choice;
    int data;
    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at End\n");
        printf("3. Insert in Ascending Order\n");
        printf("4. Delete First Node\n");
        printf("5. Delete Before Position\n");
        printf("6. Delete After Position\n");
        printf("7. Display\n");
        printf("8. Exit\n");
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
            // INSERT IN ASCENDING ORDER operation
             
            printf("Enter data to insert in ascending order: ");
            scanf("%d", &data);
            head = insertInAscendingOrder(head, data);
            break;

        case 4:
            // DELETE FIRST NODE operation
            head = deleteFirstNode(head);
            break;

        case 5:
            // DELETE BEFORE POSITION operation
             
            printf("Enter the position before which you want to delete: ");
            scanf("%d", &data);
            head = deleteBeforePosition(head, data);
            break;

        case 6:
            // DELETE AFTER POSITION operation
           
            printf("Enter the position after which you want to delete: ");
            scanf("%d", &data);
            head = deleteAfterPosition(head, data);
            break;

        case 7:
            // DISPLAY operation
            display(head);
            break;

        case 8:
            // Exit the program
            printf("Exiting the program.\n");
            return 0;

        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
