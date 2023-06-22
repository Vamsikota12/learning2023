#include <stdio.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void initializeStudents(struct Student* students, int size) {
    for (int i = 0; i < size; i++) {
        students[i].rollno = 0;
        students[i].name[0] = '\0';
        students[i].marks = 0.0;
    }
}

int main() {
    int size;
    printf("Enter the number of students: ");
    scanf("%d", &size);

    struct Student students[size];

    // Initialize the students array
    initializeStudents(students, size);

    // Print the initialized student details
    for (int i = 0; i < size; i++) {
        printf("Student %d: Roll No: %d, Name: %s, Marks: %.2f\n", i + 1, students[i].rollno, students[i].name, students[i].marks);
    }

    return 0;
}
