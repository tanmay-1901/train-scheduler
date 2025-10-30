#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
    int StudentID;
    char Name[50];
    int RollNo;
    char DOB[10];
    char BloodGroup[3];
    char Phone[10];
    float Marks;
    struct Student* next;
} Student;

Student* head = NULL;

Student* createStudent() {
    Student* newStudent = (Student*)malloc(sizeof(Student));
    if (!newStudent) {
        printf("Student creation failed!\n");
        exit(1);
    }

    printf("Enter ID: "); scanf("%d", &newStudent->StudentID);
    getchar();
    printf("Enter Name: ");
    fgets(newStudent->Name, sizeof(newStudent->Name), stdin);
    newStudent->Name[strcspn(newStudent->Name, "\n")] = '\0';
    printf("Enter Roll No: "); scanf("%d", &newStudent->RollNo);
    printf("Enter DOB (DD/MM/YYYY): "); scanf("%s", &newStudent->DOB);
    printf("Enter Blood Group: "); scanf("%s", &newStudent->BloodGroup);
    printf("Enter Phone No: "); scanf("%s", &newStudent->Phone);
    printf("Enter Marks: "); scanf("%f", &newStudent->Marks);

    newStudent->next = NULL;
    return newStudent;
}

void addStudent() {
    Student* newStudent = createStudent();
    if (head == NULL) {
        head = newStudent;
    } else {
        Student* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newStudent;
    }
    printf("Student added successfully.\n");
}

void displayStudents() {
    if (head == NULL) {
        printf("No student records found.\n");
        return;
    }

    Student* temp = head;
    printf("\nStudent Records:\n");
    while (temp != NULL) {
        printf("ID: %d | Name: %s | Roll No: %d | DOB: %s | Blood Group: %s | Phone: %s | Marks: %.2f\n",
               temp->StudentID, temp->Name, temp->RollNo, temp->DOB,
               temp->BloodGroup, temp->Phone, temp->Marks);
        temp = temp->next;
    }
}

void displayStudentByID() {
    if (head == NULL) {
        printf("No records available.\n");
        return;
    }

    int id;
    printf("Enter ID to search: ");
    scanf("%d", &id);

    Student* temp = head;
    while (temp != NULL) {
        if (temp->StudentID == id) {
            printf("ID: %d | Name: %s | Roll No: %d | DOB: %s | Blood Group: %s | Phone: %s | Marks: %.2f\n",
                   temp->StudentID, temp->Name, temp->RollNo, temp->DOB,
                   temp->BloodGroup, temp->Phone, temp->Marks);
            return;
        }
        temp = temp->next;
    }

    printf("Student with ID %d was not found.\n", id);
}

void deleteStudentByID() {
    if (head == NULL) {
        printf("No records found.\n");
        return;
    }

    int id;
    printf("Enter ID to delete: ");
    scanf("%d", &id);

    Student* temp = head;
    Student* prev = NULL;

    while (temp != NULL && temp->StudentID != id) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Student with ID %d was not found.\n", id);
        return;
    }

    if (prev == NULL) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }

    free(temp);
    printf("Student record deleted successfully.\n");
}

void deleteStudentByRollNo() {
    if (head == NULL) {
        printf("No records to delete.\n");
        return;
    }

    int roll_no;
    printf("Enter Roll No to delete: ");
    scanf("%d", &roll_no);

    Student* temp = head;
    Student* prev = NULL;

    while (temp != NULL && temp->RollNo != roll_no) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Student with Roll No %d was not found.\n", roll_no);
        return;
    }

    if (prev == NULL) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }

    free(temp);
    printf("Student record deleted successfully.\n");
}

int main() {
    int choice;

    while (1) {
        printf("\nStudent Record Management\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Display Student by ID\n");
        printf("4. Delete Student by Roll No\n");
        printf("5. Delete Student by ID\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                displayStudentByID();
                break;
            case 4:
                deleteStudentByRollNo();
                break;
            case 5:
                deleteStudentByID();
                break;
            case 6:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
