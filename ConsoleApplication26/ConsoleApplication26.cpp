#include <iostream>
#include <windows.h>
using namespace std;
struct Student {
    char name[50];
    int age;
    float gpa;
};
void createStudent(Student& student) {
    cout << "Enter student's name: ";
    cin >> student.name;
    cout << "Enter student's age: ";
    cin >> student.age;
    cout << "Enter student's GPA: ";
    cin >> student.gpa;
}
void printStudent(const Student* student) {
    cout << "Name: " << student->name << endl;
    cout << "Age: " << student->age << endl;
    cout << "GPA: " << student->gpa << endl;
}
void updateGPA(Student& student) {
    cout << "Current GPA of " << student.name << " is " << student.gpa << endl;
    cout << "Enter new GPA: ";
    cin >> student.gpa;
}
int main() {
    HANDLE handler = GetStdHandle(STD_OUTPUT_HANDLE);
    int countStudents;
    cout << "Enter number of students: ";
    cin >> countStudents;
    Student* students = new Student[countStudents];
    for (int i = 0; i < countStudents; i++) {
        cout << "Entering details for student #" << i + 1 << endl;
        createStudent(students[i]);
    }
    SetConsoleTextAttribute(handler, FOREGROUND_GREEN);
    for (int i = 0; i < countStudents; i++) {
        Sleep(1000); 
        cout << "Details for student #" << i + 1 << endl;
        printStudent(&students[i]);
    }
    for (int i = 0; i < countStudents; i++) {
        cout << "Updating GPA for student #" << i + 1 << endl;
        updateGPA(students[i]);
    }
    SetConsoleTextAttribute(handler, FOREGROUND_GREEN);
    cout << "Updated list of students:" << endl;
    for (int i = 0; i < countStudents; i++) {
        Sleep(1000);
        cout << "Student #" << i + 1 << endl;
        printStudent(&students[i]);
    }
    delete[] students;
    Sleep(10000);
    system("cls");
    SetConsoleTextAttribute(handler, FOREGROUND_RED);
    cout << "Bye!" << endl;
    return 0;
}