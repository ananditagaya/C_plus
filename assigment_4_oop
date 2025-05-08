#include <iostream>
#include <vector>
using namespace std;

class UniversitySystemException {
protected:
    string message;
public:
    UniversitySystemException(string msg) : message(msg) {}
    string what() const { return message; }
};

class EnrollmentException : public UniversitySystemException {
public:
    EnrollmentException(string msg) : UniversitySystemException("Enrollment Error: " + msg) {}
};

class GradeException : public UniversitySystemException {
public:
    GradeException(string msg) : UniversitySystemException("Grade Error: " + msg) {}
};

class PaymentException : public UniversitySystemException {
public:
    PaymentException(string msg) : UniversitySystemException("Payment Error: " + msg) {}
};

class Person {
protected:
    string name;
    int age;

public:
    Person(string n, int a) {
        if (n.empty()) throw UniversitySystemException("Name cannot be empty.");
        if (a <= 0 || a > 120) throw UniversitySystemException("Invalid age.");
        name = n;
        age = a;
    }

    virtual void displayDetails() { cout << "Name: " << name << ", Age: " << age << endl; }
    virtual double calculatePayment() { return 0.0; }
};

class Student : public Person {
protected:
    double gpa;

public:
    Student(string n, int a, double g) : Person(n, a) {
        if (g < 0.0 || g > 4.0) throw GradeException("Invalid GPA.");
        gpa = g;
    }

    void displayDetails() override {
        cout << "Student Name: " << name << ", Age: " << age << ", GPA: " << gpa << endl;
    }
};

class Professor : public Person {
protected:
    double salary;

public:
    Professor(string n, int a, double s) : Person(n, a) {
        if (s <= 0) throw PaymentException("Invalid salary.");
        salary = s;
    }

    void displayDetails() override {
        cout << "Professor Name: " << name << ", Age: " << age << ", Salary: $" << salary << endl;
    }

    double calculatePayment() override { return salary; }
};

class EnrollmentManager {
private:
    vector<string> enrolledStudents;
    int maxCapacity;
public:
    EnrollmentManager(int capacity) : maxCapacity(capacity) {}

    void enrollStudent(string studentName) {
        if (enrolledStudents.size() >= maxCapacity) throw EnrollmentException("Course is full.");
        enrolledStudents.push_back(studentName);
    }

    void displayEnrolledStudents() {
        cout << "Enrolled Students:\n";
        for (const string& student : enrolledStudents) cout << student << endl;
    }
};

class GradeBook {
private:
    vector<pair<string, double>> grades;

public:
    void addGrade(string studentName, double grade) {
        if (grade < 0.0 || grade > 100.0) throw GradeException("Invalid grade.");
        grades.push_back({studentName, grade});
    }

    void displayGrades() {
        cout << "Grades:\n";
        for (const auto& entry : grades) cout << entry.first << ": " << entry.second << endl;
    }
};

class UniversitySystem {
private:
    vector<Professor*> professors;
    vector<Student*> students;
    vector<EnrollmentManager*> enrollments;
    vector<GradeBook*> gradeBooks;

public:
    void addProfessor(Professor* p) { professors.push_back(p); }
    void addStudent(Student* s) { students.push_back(s); }
    void addEnrollmentManager(EnrollmentManager* e) { enrollments.push_back(e); }
    void addGradeBook(GradeBook* g) { gradeBooks.push_back(g); }

    void displayAllDetails() {
        cout << "University System Details:\n";
        for (Professor* p : professors) p->displayDetails();
        for (Student* s : students) s->displayDetails();
        for (EnrollmentManager* e : enrollments) e->displayEnrolledStudents();
        for (GradeBook* g : gradeBooks) g->displayGrades();
    }
};

int main() {
    try {
        UniversitySystem uni;
        Professor* prof1 = new Professor("Dr. Smith", 50, 9000);
        Student* student1 = new Student("Alice", 20, 3.8);

        EnrollmentManager* course1 = new EnrollmentManager(2);
        GradeBook* gradeBook1 = new GradeBook();

        uni.addProfessor(prof1);
        uni.addStudent(student1);
        uni.addEnrollmentManager(course1);
        uni.addGradeBook(gradeBook1);

        course1->enrollStudent("Alice");
        gradeBook1->addGrade("Alice", 95);

        uni.displayAllDetails();
    }
    catch (UniversitySystemException& e) {
        cout << "Exception: " << e.what() << endl;
    }

    return 0;
}
