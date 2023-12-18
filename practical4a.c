// Write a menu driven program for Stack that performs following operation using array.1)PUSH 2)POP 3) PEEP 4) DISPLAY
#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 10 // Maximum capacity of the stack

// Structure to represent the stack
struct Stack
{
    int items[MAX_SIZE];
    int top;
};

// Function to initialize the stack
void initialize(struct Stack *stack)
{
    stack->top = -1; // Initialize the top pointer to -1 to indicate an empty stack
}

// Function to push an element onto the stack
void push(struct Stack *stack, int value)
{
    if (stack->top < MAX_SIZE - 1)
    {
        stack->top++;
        stack->items[stack->top] = value;
        printf("%d pushed to the stack.\n", value);
    }
    else
    {
        printf("Stack overflow. Cannot push %d.\n", value);
    }
}

// Function to pop an element from the stack
int pop(struct Stack *stack)
{
    if (stack->top >= 0)
    {
        int popped = stack->items[stack->top];
        stack->top--;
        return popped;
    }
    else
    {
        printf("Stack is empty. Cannot pop.\n");
        return -1; // Return a sentinel value to indicate an empty stack
    }
}

// Function to peek at the top element of the stack
int peek(struct Stack *stack)
{
    if (stack->top >= 0)
    {
        return stack->items[stack->top];
    }
    else
    {
        printf("Stack is empty. Cannot peek.\n");
        return -1; // Return a sentinel value to indicate an empty stack
    }
}

// Function to display the elements of the stack
void display(struct Stack *stack)
{
    if (stack->top >= 0)
    {
        printf("Stack elements from top to bottom:\n");
        for (int i = stack->top; i >= 0; i--)
        {
            printf("%d\n", stack->items[i]);
        }
    }
    else
    {
        printf("Stack is empty.\n");
    }
}

int main()
{
    struct Stack stack;
    initialize(&stack); // Initialize the stack
    int value;
    int choice;
    while (1)
    {
        printf("\nMenu:\n");
        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("3. PEEP\n");
        printf("4. DISPLAY\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            // PUSH operation
           
            printf("Enter the value to PUSH: ");
            scanf("%d", &value);
            push(&stack, value);
            break;

        case 2:
            // POP operation
            printf("Popped: %d\n", pop(&stack));
            break;

        case 3:
            // PEEP operation
            printf("Peek: %d\n", peek(&stack));
            break;

        case 4:
            // DISPLAY operation
            display(&stack);
            break;

        case 5:
            // Exit the program
            printf("Exiting the program.\n");
            return 0;

        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
