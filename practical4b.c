// Write a program to convert infix notation to postfix notation using stack
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_SIZE 100

// Structure to represent the stack
struct Stack
{
    char items[MAX_SIZE];
    int top;
};

// Function to initialize the stack
void initialize(struct Stack *stack)
{
    stack->top = -1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack *stack)
{
    return stack->top == -1;
}

// Function to get the precedence of an operator
int getPrecedence(char operator)
{
    if (operator== '^')
        return 3;
    if (operator== '*' || operator== '/')
        return 2;
    if (operator== '+' || operator== '-')
        return 1;
    return 0; // Default precedence for other characters
}

// Function to convert infix expression to postfix expression
void infixToPostfix(char infix[], char postfix[])
{
    struct Stack stack;
    initialize(&stack);

    int i = 0; // Index for infix expression
    int j = 0; // Index for postfix expression

    while (infix[i] != '\0')
    {
        char token = infix[i];

        if (isalnum(token))
        {
            // If the token is an operand, add it to the postfix expression
            postfix[j] = token;
            j++;
        }
        else if (token == '(')
        {
            // If the token is an opening parenthesis, push it onto the stack
            stack.items[++stack.top] = token;
        }
        else if (token == ')')
        {
            // If the token is a closing parenthesis, pop operators from the stack and add them to the postfix expression until an opening parenthesis is encountered
            while (stack.top >= 0 && stack.items[stack.top] != '(')
            {
                postfix[j] = stack.items[stack.top];
                j++;
                stack.top--;
            }
            // Pop the opening parenthesis from the stack
            stack.top--;
        }
        else
        {
            // If the token is an operator, pop operators from the stack and add them to the postfix expression until an operator with lower precedence is encountered
            while (stack.top >= 0 && getPrecedence(stack.items[stack.top]) >= getPrecedence(token))
            {
                postfix[j] = stack.items[stack.top];
                j++;
                stack.top--;
            }
            // Push the current operator onto the stack
            stack.items[++stack.top] = token;
        }
        i++;
    }

    // Pop any remaining operators from the stack and add them to the postfix expression
    while (!isEmpty(&stack))
    {
        postfix[j] = stack.items[stack.top];
        j++;
        stack.top--;
    }

    postfix[j] = '\0'; // Null-terminate the postfix expression
}

int main()
{
    char infix[MAX_SIZE];
    char postfix[MAX_SIZE];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
