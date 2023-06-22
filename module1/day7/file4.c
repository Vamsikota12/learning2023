#include <stdio.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void swap(struct Student* a, struct Student* b) {
    struct Student temp = *a;
    *a = *b;
    *b = temp;
}

void sortStudentsDescending(struct Student* students, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (students[j].marks < students[j + 1].marks) {
                swap(&students[j], &students[j + 1]);
            }
        }
    }
}

int main() {
    int size;
    printf("Enter the number of students: ");
    scanf("%d", &size);

    struct Student students[size];

    printf("Enter the student details:\n");
    for (int i = 0; i < size; i++) {
        printf("Student %d:\n", i + 1);

        printf("Enter Roll No: ");
        scanf("%d", &students[i].rollno);

        printf("Enter Name: ");
        scanf("%s", students[i].name);

        printf("Enter Marks: ");
        scanf("%f", &students[i].marks);

        printf("\n");
    }

    // Sort the student array in descending order based on marks
    sortStudentsDescending(students, size);

    // Display the sorted student details
    printf("Students sorted in descending order based on marks:\n");
    for (int i = 0; i < size; i++) {
        printf("Student %d: Roll No: %d, Name: %s, Marks: %.2f\n", i + 1, students[i].rollno, students[i].name, students[i].marks);
    }

    return 0;
}

