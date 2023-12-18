/*
Write a menu driven program using array to read 10 elements from the user and perform following
operations on array using user defined functions. 1) Addition 2) Average 3) Maximum Value
4) Minimum Value
*/
#include <stdio.h>

// Function to read 10 elements from the user
void readArray(int arr[], int size)
{
    printf("Enter 10 elements:\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
}

// Function to calculate the sum of elements in an array
int calculateSum(int arr[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return sum;
}

// Function to calculate the average of elements in an array
float calculateAverage(int arr[], int size)
{
    int sum = calculateSum(arr, size);
    return (float)sum / size;
}

// Function to find the maximum value in an array
int findMax(int arr[], int size)
{
    int max = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

// Function to find the minimum value in an array
int findMin(int arr[], int size)
{
    int min = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    return min;
}

int main()
{
    int arr[10];        // Declare an array to store 10 elements
    readArray(arr, 10); // Call the function to read elements
    printf("Elements have been read and stored in the array.\n");

    int choice;
    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Calculate Sum\n");
        printf("2. Calculate Average\n");
        printf("3. Find Maximum Value\n");
        printf("4. Find Minimum Value\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            // Calculate and display sum
            printf("Sum of elements: %d\n", calculateSum(arr, 10));
            break;

        case 2:
            // Calculate and display average
            printf("Average of elements: %.2f\n", calculateAverage(arr, 10));
            break;

        case 3:
            // Find and display maximum value
            printf("Maximum value: %d\n", findMax(arr, 10));
            break;

        case 4:
            // Find and display minimum value
            printf("Minimum value: %d\n", findMin(arr, 10));
            break;

        case 5:
            printf("Exiting the program.\n");
            return 0;

        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
