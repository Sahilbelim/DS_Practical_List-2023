/*
Write a menu driven program to create a dynamic list using dynamic memory allocation functions
(malloc(), calloc(), realloc() and free()). First program should ask the user to input the initial size of the list and then give a menu to add or delete the elements in the list. The program should have following menus.1)Add an element 2) Delete last element 3) Display the list elements 4) Rese
*/

#include <stdio.h>
#include <stdlib.h>

// Structure to represent the dynamic list
struct DynamicList
{
    int *elements;
    int size;
    int capacity;
};

// Function to create an empty dynamic list
struct DynamicList *createDynamicList(int initialSize)
{
    struct DynamicList *list = (struct DynamicList *)malloc(sizeof(struct DynamicList));
    if (list == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1); // Exit the program if memory allocation fails
    }
    list->elements = (int *)malloc(initialSize * sizeof(int));
    if (list->elements == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1); // Exit the program if memory allocation fails
    }
    list->size = 0;
    list->capacity = initialSize;
    return list;
}

// Function to add an element to the dynamic list
void addElement(struct DynamicList *list, int element)
{
    if (list->size == list->capacity)
    {
        // If the list is full, reallocate memory to increase capacity
        list->capacity *= 2; // You can choose a different resizing strategy
        list->elements = (int *)realloc(list->elements, list->capacity * sizeof(int));
        if (list->elements == NULL)
        {
            printf("Memory allocation failed.\n");
            exit(1); // Exit the program if memory allocation fails
        }
    }
    list->elements[list->size] = element;
    list->size++;
}

// Function to delete the last element from the dynamic list
void deleteLastElement(struct DynamicList *list)
{
    if (list->size > 0)
    {
        list->size--;
    }
}

// Function to display the elements in the dynamic list
void displayList(struct DynamicList *list)
{
    printf("List elements: ");
    for (int i = 0; i < list->size; i++)
    {
        printf("%d ", list->elements[i]);
    }
    printf("\n");
}

// Function to resize the dynamic list
void resizeList(struct DynamicList *list, int newSize)
{
    list->capacity = newSize;
    list->elements = (int *)realloc(list->elements, newSize * sizeof(int));
    if (list->elements == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1); // Exit the program if memory allocation fails
    }
}

int main()
{
    int initialSize;

    // Get the initial size of the dynamic list from the user
    printf("Enter the initial size of the dynamic list: ");
    scanf("%d", &initialSize);

    // Create the dynamic list
    struct DynamicList *list = createDynamicList(initialSize);

    int choice, element;

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Add an element\n");
        printf("2. Delete last element\n");
        printf("3. Display list elements\n");
        printf("4. Resize list\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            // Add an element to the list
            printf("Enter the element to add: ");
            scanf("%d", &element);
            addElement(list, element);
            break;

        case 2:
            // Delete the last element from the list
            deleteLastElement(list);
            break;

        case 3:
            // Display list elements
            displayList(list);
            break;

        case 4:
            // Resize list
            printf("Enter the new size for the list: ");
            scanf("%d", &element);
            resizeList(list, element);
            break;

        case 5:
            // Exit the program
            free(list->elements);
            free(list);
            printf("Exiting the program.\n");
            return 0;

        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
}
