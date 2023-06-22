#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void parseString(const char* input, struct Student* students, int size) {
    const char* delimiter = " ";

    char* inputCopy = strdup(input);
    char* token = strtok(inputCopy, delimiter);

    for (int i = 0; i < size; i++) {
        if (token == NULL) {
            fprintf(stderr, "Insufficient input tokens.\n");
            break;
        }

        students[i].rollno = atoi(token);

        token = strtok(NULL, delimiter);
        if (token == NULL) {
            fprintf(stderr, "Insufficient input tokens.\n");
            break;
        }

        strncpy(students[i].name, token, sizeof(students[i].name) - 1);
        students[i].name[sizeof(students[i].name) - 1] = '\0';

        token = strtok(NULL, delimiter);
        if (token == NULL) {
            fprintf(stderr, "Insufficient input tokens.\n");
            break;
        }

        students[i].marks = atof(token);

        token = strtok(NULL, delimiter);
    }

    free(inputCopy);
}

int main() {
    int size;
    printf("Enter the number of students: ");
    scanf("%d", &size);
    getchar();  // Consume the newline character

    struct Student* students = (struct Student*)malloc(size * sizeof(struct Student));

    printf("Enter the student details in the format 'rollno name marks':\n");
    for (int i = 0; i < size; i++) {
        char input[100];
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';  // Remove the trailing newline character
        parseString(input, &students[i], 1);
    }

    // Print the student details
    printf("\nStudent Details:\n");
    for (int i = 0; i < size; i++) {
        printf("Roll No: %d, Name: %s, Marks: %.2f\n", students[i].rollno, students[i].name, students[i].marks);
    }

    free(students);

    return 0;
}
