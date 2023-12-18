/*
Write a menu driven program to implement following searching methods. 1)Linear Searching
2)Binary Searching
*/
#include <stdio.h>

// Function for Linear Search
int linearSearch(int arr[], int n, int target)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
        {
            return i; // Element found at index i
        }
    }
    return -1; // Element not found
}

// Function for Binary Search
int binarySearch(int arr[], int left, int right, int target)
{
    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
        {
            return mid; // Element found at index mid
        }

        if (arr[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return -1; // Element not found
}

int main()
{
    int choice, n, target;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements in ascending order:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &target);

    printf("\nMenu:\n");
    printf("1. Linear Search\n");
    printf("2. Binary Search\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        // Linear Search
        {
            int linearResult = linearSearch(arr, n, target);
            if (linearResult != -1)
            {
                printf("Element found at index %d.\n", linearResult);
            }
            else
            {
                printf("Element not found.\n");
            }
        }
        break;

    case 2:
        // Binary Search
        {
            int binaryResult = binarySearch(arr, 0, n - 1, target);
            if (binaryResult != -1)
            {
                printf("Element found at index %d.\n", binaryResult);
            }
            else
            {
                printf("Element not found.\n");
            }
        }
        break;

    default:
        printf("Invalid choice. Please choose 1 or 2.\n");
    }

    return 0;
}
