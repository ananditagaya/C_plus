#include <iostream>
#include <vector>
using namespace std;

class Person {
private:
    string name;
    int age;
    int id;
    string contactInfo;

public:
    Person(string n, int a, int i, string c) : name(n), age(a), id(i), contactInfo(c) {}

    virtual void displayDetails() {
        cout << "Name: " << name << ", Age: " << age << ", ID: " << id << ", Contact: " << contactInfo << endl;
    }

    virtual double calculatePayment() { return 0.0; }

    string getName() { return name; }
    void setName(string n) { if (!n.empty()) name = n; }

    int getAge() { return age; }
    void setAge(int a) { if (a > 0 && a < 120) age = a; }

    int getID() { return id; }
    void setID(int i) { if (i > 0) id = i; }

    string getContactInfo() { return contactInfo; }
    void setContactInfo(string c) { if (!c.empty()) contactInfo = c; }
};

class Student : public Person {
private:
    string enrollmentDate;
    string program;
    double gpa;

public:
    Student(string n, int a, int i, string c, string ed, string p, double g)
        : Person(n, a, i, c), enrollmentDate(ed), program(p), gpa(g) {}

    void displayDetails() override {
        cout << "Student: " << getName() << ", Age: " << getAge() << ", ID: " << getID()
             << ", Contact: " << getContactInfo() << ", Enrollment: " << enrollmentDate
             << ", Program: " << program << ", GPA: " << gpa << endl;
    }

    double calculatePayment() override { return 2000.0; }

    string getProgram() { return program; }
    void setProgram(string p) { if (!p.empty()) program = p; }

    double getGPA() { return gpa; }
    void setGPA(double g) { if (g >= 0.0 && g <= 4.0) gpa = g; }
};

class Professor : public Person {
private:
    string department;
    string specialization;
    string hireDate;
    double salary;

public:
    Professor(string n, int a, int i, string c, string d, string s, string hd, double sal)
        : Person(n, a, i, c), department(d), specialization(s), hireDate(hd), salary(sal) {}

    void displayDetails() override {
        cout << "Professor: " << getName() << ", Age: " << getAge() << ", ID: " << getID()
             << ", Contact: " << getContactInfo() << ", Department: " << department
             << ", Specialization: " << specialization << ", Hire Date: " << hireDate
             << ", Salary: $" << salary << endl;
    }

    double calculatePayment() override { return salary; }
};

class Course {
private:
    string code;
    string title;
    int credits;
    string description;

public:
    Course(string c, string t, int cr, string d) : code(c), title(t), credits(cr), description(d) {}

    void displayDetails() {
        cout << "Course: " << title << " (" << code << "), Credits: " << credits << ", Description: " << description << endl;
    }
};

class Department {
private:
    string name;
    string location;
    double budget;

public:
    Department(string n, string l, double b) : name(n), location(l), budget(b) {}

    void displayDetails() {
        cout << "Department: " << name << ", Location: " << location << ", Budget: $" << budget << endl;
    }
};

class GradeBook {
private:
    vector<pair<int, double>> studentGrades;

public:
    void addGrade(int studentID, double grade) {
        if (grade >= 0.0 && grade <= 100.0) studentGrades.push_back({studentID, grade});
    }

    double calculateAverageGrade() {
        if (studentGrades.empty()) return 0.0;
        double sum = 0.0;
        for (auto &entry : studentGrades) sum += entry.second;
        return sum / studentGrades.size();
    }

    double getHighestGrade() {
        double highest = 0.0;
        for (auto &entry : studentGrades) if (entry.second > highest) highest = entry.second;
        return highest;
    }

    void getFailingStudents(double passThreshold) {
        cout << "Failing Students:\n";
        for (auto &entry : studentGrades) if (entry.second < passThreshold)
            cout << "Student ID: " << entry.first << ", Grade: " << entry.second << endl;
    }
};

class EnrollmentManager {
private:
    vector<int> studentIDs;
    vector<string> courses;

public:
    void enrollStudent(int studentID, string course) {
        studentIDs.push_back(studentID);
        courses.push_back(course);
    }

    void dropStudent(int studentID, string course) {
        for (size_t i = 0; i < studentIDs.size(); i++) {
            if (studentIDs[i] == studentID && courses[i] == course) {
                studentIDs.erase(studentIDs.begin() + i);
                courses.erase(courses.begin() + i);
                break;
            }
        }
    }

    int getEnrollmentCount(string course) {
        int count = 0;
        for (const string &c : courses) if (c == course) count++;
        return count;
    }
};

void testPolymorphism(Person* p) {
    p->displayDetails();
    cout << "Payment: $" << p->calculatePayment() << endl;
}

int main() {
    vector<Person*> universityPeople = {
        new Student("cheshna", 20, 101, "mehra@email.com", "2022", "Computer Science", 10.9),
        new Professor("Dr. amandeep", 45, 201, "northcap@university.edu", "Engineering", "DS", "2010", 8000)
    };

    for (Person* p : universityPeople) testPolymorphism(p);

    for (Person* p : universityPeople) delete p;

    return 0;
}
