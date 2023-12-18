#include <stdio.h>

#define MAX_SIZE 100 // Maximum capacity of the queue

// Structure to represent the queue
struct Queue
{
    int items[MAX_SIZE];
    int front, rear;
};

// Function to initialize the queue
void initialize(struct Queue *queue)
{
    queue->front = queue->rear = -1; // Initialize both front and rear pointers to -1
}

// Function to insert an element into the queue
void insert(struct Queue *queue, int value)
{
    if (queue->rear == MAX_SIZE - 1)
    {
        printf("Queue is full. Cannot insert %d.\n", value);
        return;
    }

    if (queue->front == -1)
    {
        // If the queue is empty, set the front pointer to 0
        queue->front = 0;
    }

    queue->rear++;
    queue->items[queue->rear] = value;
    printf("%d inserted into the queue.\n", value);
}

// Function to delete an element from the queue
int deleteElement(struct Queue *queue)
{
    if (queue->front == -1)
    {
        printf("Queue is empty. Cannot delete.\n");
        return -1; // Return a sentinel value to indicate an empty queue
    }

    int deleted = queue->items[queue->front];

    if (queue->front == queue->rear)
    {
        // If there was only one element in the queue, reset front and rear pointers
        queue->front = queue->rear = -1;
    }
    else
    {
        queue->front++;
    }
    if (deleted==-1)
    {
        printf("Queue is empty.\n");

        return 0;
    }
        return deleted;
}

// Function to display the elements of the queue
void display(struct Queue *queue)
{
    if (queue->front == -1)
    {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements from front to rear:\n");
    for (int i = queue->front; i <= queue->rear; i++)
    {
        printf("%d\n", queue->items[i]);
    }
}

int main()
{
    struct Queue queue;
    initialize(&queue); // Initialize the queue

    int choice;
    int value; // Declare the variable here

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. INSERT\n");
        printf("2. DELETE\n");
        printf("3. DISPLAY\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            // INSERT operation
            printf("Enter the value to INSERT: ");
            scanf("%d", &value);
            insert(&queue, value);
            break;

        case 2:
            // DELETE operation
            printf("Deleted: %d\n", deleteElement(&queue));
            break;

        case 3:
            // DISPLAY operation
            display(&queue);
            break;

        case 4:
            // Exit the program
            printf("Exiting the program.\n");
            return 0;

        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
