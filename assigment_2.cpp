#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int rollNumber;
    float cgpa;
    vector<string> courses;

public:
    Student() {
        name = "Unknown";
        rollNumber = 0;
        cgpa = 0.0;
    }

    Student(string n, int roll, float c) {
        name = n;
        rollNumber = roll;
        setCGPA(c);
    }

    Student(const Student& other) {
        name = other.name;
        rollNumber = other.rollNumber;
        cgpa = other.cgpa;
        courses = other.courses;
    }

    void addCourse(string courseName) {
        if (courseName.empty()) {
            cout << "Course name cannot be empty.\n";
            return;
        }
        courses.push_back(courseName);
        cout << "Course \"" << courseName << "\" added successfully.\n";
    }

    void setCGPA(float newCGPA) {
        if (newCGPA < 0.0 || newCGPA > 4.0) {
            cout << "Invalid CGPA! Must be between 0.0 and 4.0.\n";
        } else {
            cgpa = newCGPA;
        }
    }

    void displayInfo() const {
        cout << "\nStudent Info:\n";
        cout << "Name       : " << name << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "CGPA       : " << cgpa << endl;
        cout << "Courses    : ";
        if (courses.empty()) {
            cout << "None\n";
        } else {
            for (const string& course : courses) {
                cout << course << ", ";
            }
            cout << endl;
        }
    }

    int getRollNumber() const {
        return rollNumber;
    }
};

class StudentManagementSystem {
private:
    vector<Student> students;

public:
    void addStudent(const Student& s) {
        students.push_back(s);
        cout << "Student added successfully.\n";
    }

    void searchStudent(int roll) const {
        for (const Student& s : students) {
            if (s.getRollNumber() == roll) {
                s.displayInfo();
                return;
            }
        }
        cout << "No student found with Roll Number: " << roll << endl;
    }

    void displayAllStudents() const {
        if (students.empty()) {
            cout << "No student records available.\n";
        } else {
            for (const Student& s : students) {
                s.displayInfo();
            }
        }
    }
};

int main() {
    StudentManagementSystem sms;

    Student s1("David", 201, 3.8);
    Student s2("Emma", 202, 3.4);

    s1.addCourse("Computer Science");
    s1.addCourse("Data Structures");

    s2.addCourse("Economics");
    s2.addCourse("Statistics");

    s2.setCGPA(3.6);

    sms.addStudent(s1);
    sms.addStudent(s2);

    sms.displayAllStudents();

    sms.searchStudent(202);
    sms.searchStudent(303);

    return 0;
}
