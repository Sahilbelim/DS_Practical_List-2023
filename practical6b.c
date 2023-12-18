// Write a program to implement stack and queue using linked list
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the linked list
struct Node
{
    int data;
    struct Node *next;
};

// Stack functions
struct Node *push(struct Node *top, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = top;
    return newNode; // The new node becomes the new top
}

struct Node *pop(struct Node *top)
{
    if (top == NULL)
    {
        printf("Stack is empty. Cannot pop.\n");
        return NULL;
    }
    struct Node *temp = top;
    top = top->next;
    free(temp);
    return top;
}

// Queue functions
struct Node *enqueue(struct Node *rear, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (rear == NULL)
    {
        // If the queue is empty, the new node becomes both front and rear
        return newNode;
    }
    else
    {
        rear->next = newNode;
        return newNode; // The new node becomes the new rear
    }
}

struct Node *dequeue(struct Node *front)
{
    if (front == NULL)
    {
        printf("Queue is empty. Cannot dequeue.\n");
        return NULL;
    }
    struct Node *temp = front;
    front = front->next;
    free(temp);
    return front;
}

// Display function for both stack and queue
void display(struct Node *front)
{
    struct Node *current = front;
    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main()
{
    struct Node *stackTop = NULL;   // Initialize an empty stack
    struct Node *queueFront = NULL; // Initialize an empty queue
    struct Node *queueRear = NULL;  // Initialize an empty queue

    int choice;
    int data;
    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Push (Stack)\n");
        printf("2. Pop (Stack)\n");
        printf("3. Enqueue (Queue)\n");
        printf("4. Dequeue (Queue)\n");
        printf("5. Display (Stack/Queue)\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            // PUSH (Stack) operation
          
            printf("Enter data to push onto the stack: ");
            scanf("%d", &data);
            stackTop = push(stackTop, data);
            break;

        case 2:
            // POP (Stack) operation
            stackTop = pop(stackTop);
            break;

        case 3:
            // ENQUEUE (Queue) operation
           
            printf("Enter data to enqueue: ");
            scanf("%d", &data);
            queueRear = enqueue(queueRear, data);
            if (queueFront == NULL)
            {
                // If the front is null, update it to the new node
                queueFront = queueRear;
            }
            break;

        case 4:
            // DEQUEUE (Queue) operation
            queueFront = dequeue(queueFront);
            if (queueFront == NULL)
            {
                // If the front becomes null, update the rear as well
                queueRear = NULL;
            }
            break;

        case 5:
            // DISPLAY operation (Stack or Queue)
            printf("Stack: ");
            display(stackTop);
            printf("Queue: ");
            display(queueFront);
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
