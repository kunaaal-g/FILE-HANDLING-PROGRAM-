#include <stdio.h>
#include <stdlib.h>

void createFile(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) 
    {
        printf("Error creating file.\n");
        return;
    }
    fprintf(file, "This is the initial content.\n");
    printf("File '%s' created successfully.\n", filename);
    fclose(file);
}

void writeFile(const char *filename) 
{
    FILE *file = fopen(filename, "w");
    if (file == NULL) 
    {
        printf("Error opening file for writing.\n");
        return;
    }
    char data[100];
    printf("Enter data to write (overwrite file): ");
    getchar();
    fgets(data, sizeof(data), stdin);
    fprintf(file, "%s", data);
    printf("Data written to '%s'.\n", filename);
    fclose(file);
}

void appendFile(const char *filename) 
{
    FILE *file = fopen(filename, "a");
    if (file == NULL) 
    {
        printf("Error opening file for appending.\n");
        return;
    }
    char data[100];
    printf("Enter data to append: ");
    getchar(); 
    fgets(data, sizeof(data), stdin);
    fprintf(file, "%s", data);
    printf("Data appended to '%s'.\n", filename);
    fclose(file);
}

void readFile(const char *filename) 
{
    FILE *file = fopen(filename, "r");
    if (file == NULL) 
    {
        printf("Error opening file for reading.\n");
        return;
    }
    int ch;
    printf("Contents of '%s':\n", filename);
    while ((ch = fgetc(file)) != EOF) 
    {
        putchar(ch);
    }
    fclose(file);
}

int main() 
{
    const char *filename = "sample.txt";
    int choice;

    while (1) 
    {
        printf("\n\n--- File Operations Menu ---\n");
        printf("1. Create File\n");
        printf("2. Write to File\n");
        printf("3. Append to File\n");
        printf("4. Read from File\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                createFile(filename);
                break;
            case 2:
                writeFile(filename);
                break;
            case 3:
                appendFile(filename);
                break;
            case 4:
                readFile(filename);
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}