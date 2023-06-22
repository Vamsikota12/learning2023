#include <stdio.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void displayStudents(const struct Student* students, int size) {
    for (int i = 0; i < size; i++) {
        printf("Student %d: Roll No: %d, Name: %s, Marks: %.2f\n", i + 1, students[i].rollno, students[i].name, students[i].marks);
    }
}

int main() {
    int size;
    printf("Enter the number of students: ");
    scanf("%d", &size);

    struct Student students[size];

    // Populate the students array with data

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

    // Display the student details
    displayStudents(students, size);

    return 0;
}
