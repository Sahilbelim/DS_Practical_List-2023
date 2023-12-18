// Write a menu driven program to store and display 10 student information using structure and user-defined functions.
#include <stdio.h>
#include <string.h>

// Structure to represent student information
struct Student
{
    int rollNumber;
    char name[50];
    float marks;
};

// Function to add student information
void addStudent(struct Student students[], int index)
{
    printf("Enter details for student %d:\n", index + 1);
    printf("Roll Number: ");
    scanf("%d", &students[index].rollNumber);
    printf("Name: ");
    scanf(" %s", students[index].name);
    printf("Marks: ");
    scanf("%f", &students[index].marks);
}

// Function to display student information
void displayStudents(struct Student students[], int count)
{
    printf("Student Information:\n");
    for (int i = 0; i < count; i++)
    {
        printf("Student %d:\n", i + 1);
        printf("Roll Number: %d\n", students[i].rollNumber);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
        printf("\n");
    }
}

// Function to sort students by roll number
void sortByRollNumber(struct Student students[], int count)
{
    // Sort students using a simple bubble sort algorithm
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - i - 1; j++)
        {
            if (students[j].rollNumber > students[j + 1].rollNumber)
            {
                // Swap students[j] and students[j+1]
                struct Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

// Function to search for a student by roll number
void searchByRollNumber(struct Student students[], int count, int rollNumber)
{
    int found = 0;
    for (int i = 0; i < count; i++)
    {
        if (students[i].rollNumber == rollNumber)
        {
            printf("Student found:\n");
            printf("Roll Number: %d\n", students[i].rollNumber);
            printf("Name: %s\n", students[i].name);
            printf("Marks: %.2f\n", students[i].marks);
            found = 1;
            break; // Stop searching once the student is found
        }
    }
    if (!found)
    {
        printf("Student with Roll Number %d not found.\n", rollNumber);
    }
}

// Function to edit student information
void editStudent(struct Student students[], int count)
{
    int rollNumber;
    printf("Enter the Roll Number of the student to edit: ");
    scanf("%d", &rollNumber);

    int found = 0;
    for (int i = 0; i < count; i++)
    {
        if (students[i].rollNumber == rollNumber)
        {
            printf("Editing student with Roll Number %d:\n", rollNumber);
            // Allow the user to edit the student's name and marks
            printf("Enter new Name: ");
            scanf(" %s", students[i].name);
            printf("Enter new Marks: ");
            scanf("%f", &students[i].marks);
            printf("Student information updated.\n");
            found = 1;
            break; // Stop searching once the student is found
        }
    }

    if (!found)
    {
        printf("Student with Roll Number %d not found.\n", rollNumber);
    }
}

// Function to save student information to a file
void saveStudentsToFile(struct Student students[], int count)
{
    FILE *file = fopen("student_data.txt", "w");
    if (file == NULL)
    {
        printf("Error opening file for writing.\n");
        return;
    }
    for (int i = 0; i < count; i++)
    {
        fprintf(file, "%d %s %.2f\n", students[i].rollNumber, students[i].name, students[i].marks);
    }
    fclose(file);
    printf("Student information saved to 'student_data.txt'.\n");
}

// Function to load student information from a file
void loadStudentsFromFile(struct Student students[], int *count)
{
    FILE *file = fopen("student_data.txt", "r");
    if (file == NULL)
    {
        printf("No student data found.\n");
        return;
    }
    *count = 0;
    while (*count < 10 && fscanf(file, "%d %[^\n] %f", &students[*count].rollNumber, students[*count].name, &students[*count].marks) != EOF)
    {
        (*count)++;
    }
    fclose(file);
    printf("Student information loaded from 'student_data.txt'.\n");
}

int main()
{
    struct Student students[10]; // Array to store information for 10 students
    int count = 0;               // Current number of students added

    int choice;
    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Sort by Roll Number\n");
        printf("4. Search by Roll Number\n");
        printf("5. Edit Student Information\n");
        printf("6. Save Student Information to File\n");
        printf("7. Load Student Information from File\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            // Add a student
            if (count < 10)
            {
                addStudent(students, count);
                count++;
            }
            else
            {
                printf("Maximum number of students reached.\n");
            }
            break;

        case 2:
            // Display student information
            if (count > 0)
            {
                displayStudents(students, count);
            }
            else
            {
                printf("No student information available.\n");
            }
            break;

        case 3:
            // Sort by Roll Number
            if (count > 0)
            {
                sortByRollNumber(students, count);
                printf("Students sorted by roll number:\n");
                displayStudents(students, count);
            }
            else
            {
                printf("Sorting requires at least two students.\n");
            }
            break;

        case 4:
            // Search by Roll Number
            if (count > 0)
            {
                int rollNumber;
                printf("Enter the Roll Number to search: ");
                scanf("%d", &rollNumber);
                searchByRollNumber(students, count, rollNumber);
            }
            else
            {
                printf("No student information available.\n");
            }
            break;

        case 5:
            // Edit Student Information
            if (count > 0)
            {
                editStudent(students, count);
            }
            else
            {
                printf("No student information available.\n");
            }
            break;

        case 6:
            // Save Student Information to File
            if (count > 0)
            {
                saveStudentsToFile(students, count);
            }
            else
            {
                printf("No student information available to save.\n");
            }
            break;

        case 7:
            // Load Student Information from File
            loadStudentsFromFile(students, &count);
            break;

        case 8:
            printf("Exiting the program.\n");
            return 0;

        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
