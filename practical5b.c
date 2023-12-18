#include <stdio.h>

#define MAX_SIZE 100 // Maximum capacity of the circular queue

// Structure to represent the circular queue
struct CircularQueue
{
    int items[MAX_SIZE];
    int front, rear;
};

// Function to initialize the circular queue
void initialize(struct CircularQueue *queue)
{
    queue->front = queue->rear = -1; // Initialize both front and rear pointers to -1
}

// Function to insert an element into the circular queue
void insert(struct CircularQueue *queue, int value)
{
    if ((queue->rear + 1) % MAX_SIZE == queue->front)
    {
        printf("Circular Queue is full. Cannot insert %d.\n", value);
        return;
    }

    if (queue->front == -1)
    {
        // If the queue is empty, set both front and rear pointers to 0
        queue->front = queue->rear = 0;
    }
    else
    {
        // Move rear pointer in a circular manner
        queue->rear = (queue->rear + 1) % MAX_SIZE;
    }

    queue->items[queue->rear] = value;
    printf("%d inserted into the circular queue.\n", value);
}

// Function to delete an element from the circular queue
int deleteElement(struct CircularQueue *queue)
{
    if (queue->front == -1)
    {
        printf("Circular Queue is empty. Cannot delete.\n");
        return -1; // Return a sentinel value to indicate an empty queue
    }

    int deleted = queue->items[queue->front];

    if (queue->front == queue->rear)
    {
        // If there was only one element in the queue, reset both front and rear pointers
        queue->front = queue->rear = -1;
    }
    else
    {
        // Move front pointer in a circular manner
        queue->front = (queue->front + 1) % MAX_SIZE;
    }

    return deleted;
}

// Function to display the elements of the circular queue
void display(struct CircularQueue *queue)
{
    if (queue->front == -1)
    {
        printf("Circular Queue is empty.\n");
        return;
    }

    printf("Circular Queue elements from front to rear:\n");

    int i = queue->front;
    do
    {
        printf("%d\n", queue->items[i]);
        i = (i + 1) % MAX_SIZE;
    } while (i != (queue->rear + 1) % MAX_SIZE);
}

int main()
{
    struct CircularQueue queue;
    initialize(&queue); // Initialize the circular queue

    int choice,value;
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
