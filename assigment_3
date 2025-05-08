#include <iostream>
#include <vector>
using namespace std;

class Person {
protected:
    string name;
    int age;

public:
    Person(string n, int a) : name(n), age(a) {}

    virtual void displayDetails() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }

    virtual double calculatePayment() {
        return 0.0;
    }
};

class Student : public Person {
protected:
    double gpa;

public:
    Student(string n, int a, double g) : Person(n, a), gpa(g) {}

    void displayDetails() override {
        cout << "Student Name: " << name << ", Age: " << age << ", GPA: " << gpa << endl;
    }
};

class UndergraduateStudent : public Student {
private:
    string major, minor;
    int gradYear;

public:
    UndergraduateStudent(string n, int a, double g, string m, string mi, int gy) 
        : Student(n, a, g), major(m), minor(mi), gradYear(gy) {}

    void displayDetails() override {
        cout << "Undergraduate Student: " << name << ", Age: " << age 
             << ", GPA: " << gpa << ", Major: " << major 
             << ", Minor: " << minor << ", Graduation Year: " << gradYear << endl;
    }
};

class GraduateStudent : public Student {
private:
    string researchTopic, advisor, thesisTitle;
    bool isTeachingAssistant, isResearchAssistant;

public:
    GraduateStudent(string n, int a, double g, string rt, string adv, string tt, bool ta, bool ra) 
        : Student(n, a, g), researchTopic(rt), advisor(adv), thesisTitle(tt), 
          isTeachingAssistant(ta), isResearchAssistant(ra) {}

    void displayDetails() override {
        cout << "Graduate Student: " << name << ", Age: " << age 
             << ", GPA: " << gpa << ", Research Topic: " << researchTopic 
             << ", Advisor: " << advisor << ", Thesis Title: " << thesisTitle 
             << ", Teaching Assistant: " << (isTeachingAssistant ? "Yes" : "No") 
             << ", Research Assistant: " << (isResearchAssistant ? "Yes" : "No") << endl;
    }
};

class Professor : public Person {
protected:
    double baseSalary;
    int yearsOfService;
    string academicRank;

public:
    Professor(string n, int a, double s, int y, string rank) 
        : Person(n, a), baseSalary(s), yearsOfService(y), academicRank(rank) {}

    void displayDetails() override {
        cout << "Professor Name: " << name << ", Age: " << age 
             << ", Base Salary: $" << baseSalary << ", Years of Service: " << yearsOfService 
             << ", Rank: " << academicRank << endl;
    }

    virtual double calculatePayment() override {
        return baseSalary + (yearsOfService * 500);
    }
};

class AssistantProfessor : public Professor {
private:
    int publications;

public:
    AssistantProfessor(string n, int a, double s, int y, string rank, int p) 
        : Professor(n, a, s, y, rank), publications(p) {}

    void displayDetails() override {
        cout << "Assistant Professor: " << name << ", Age: " << age 
             << ", Salary: $" << calculatePayment() << ", Publications: " << publications << endl;
    }
};

class AssociateProfessor : public Professor {
private:
    int tenureYears;

public:
    AssociateProfessor(string n, int a, double s, int y, string rank, int t) 
        : Professor(n, a, s, y, rank), tenureYears(t) {}

    void displayDetails() override {
        cout << "Associate Professor: " << name << ", Age: " << age 
             << ", Salary: $" << calculatePayment() << ", Tenure Years: " << tenureYears << endl;
    }
};

class FullProfessor : public Professor {
private:
    double researchGrants;

public:
    FullProfessor(string n, int a, double s, int y, string rank, double rg) 
        : Professor(n, a, s, y, rank), researchGrants(rg) {}

    double calculatePayment() override {
        return baseSalary + (yearsOfService * 500) + researchGrants;
    }

    void displayDetails() override {
        cout << "Full Professor: " << name << ", Age: " << age 
             << ", Salary: $" << calculatePayment() << ", Research Grants: $" << researchGrants << endl;
    }
};

class Department {
private:
    string name;
    vector<Professor*> professors;

public:
    Department(string n) : name(n) {}

    void addProfessor(Professor* p) {
        professors.push_back(p);
    }

    void displayProfessors() {
        cout << "Department: " << name << endl;
        for (Professor* p : professors) {
            p->displayDetails();
        }
    }
};

class Course {
private:
    string courseName;
    Professor* instructor;
    vector<Student*> students;

public:
    Course(string cn, Professor* p) : courseName(cn), instructor(p) {}

    void enrollStudent(Student* s) {
        students.push_back(s);
    }

    void displayCourse() {
        cout << "Course: " << courseName << endl;
        instructor->displayDetails();
        for (Student* s : students) {
            s->displayDetails();
        }
    }
};

class University {
private:
    vector<Department*> departments;

public:
    void addDepartment(Department* d) {
        departments.push_back(d);
    }

    void displayUniversity() {
        for (Department* d : departments) {
            d->displayProfessors();
        }
    }
};

class Classroom {
private:
    string roomNumber;
    int capacity;

public:
    Classroom(string rn, int c) : roomNumber(rn), capacity(c) {}

    void displayClassroom() {
        cout << "Classroom: " << roomNumber << ", Capacity: " << capacity << endl;
    }
};

class Schedule {
private:
    vector<string> timeSlots;

public:
    void addTimeSlot(string ts) {
        timeSlots.push_back(ts);
    }

    void displaySchedule() {
        for (string ts : timeSlots) {
            cout << "Time Slot: " << ts << endl;
        }
    }
};

int main() {
    University uni;
    Department* csDept = new Department("Computer Science");

    FullProfessor* prof1 = new FullProfessor("Dr. Smith", 50, 10000, 20, "Senior", 50000);
    csDept->addProfessor(prof1);

    uni.addDepartment(csDept);
    uni.displayUniversity();

    Course* algo = new Course("Algorithms", prof1);
    Student* s1 = new UndergraduateStudent("Alice", 20, 3.8, "CS", "Math", 2026);
    algo->enrollStudent(s1);
    algo->displayCourse();

    delete csDept;
    delete prof1;
    delete algo;
    delete s1;

    return 0;
}
