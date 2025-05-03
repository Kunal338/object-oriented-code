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
        name = "";
        rollNumber = 0;
        cgpa = 0.0;
    }

    Student(string n, int r, float c) {
        name = n;
        rollNumber = r;
        setCGPA(c);
    }

    Student(const Student& s) {
        name = s.name;
        rollNumber = s.rollNumber;
        cgpa = s.cgpa;
        courses = s.courses;
    }

    ~Student() {
        cout << "Destructor called for Student: " << name << endl;
    }

    void addCourse(string course) {
        courses.push_back(course);
    }

    void setCGPA(float newCGPA) {
        if (newCGPA >= 0.0 && newCGPA <= 4.0) {
            cgpa = newCGPA;
        } else {
            cout << "Invalid CGPA! Must be between 0.0 and 4.0." << endl;
        }
    }

    void displayInfo() {
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "CGPA: " << cgpa << endl;
        cout << "Courses Enrolled: ";
        for (string course : courses) {
            cout << course << " ";
        }
        cout << endl;
    }

    int getRollNumber() {
        return rollNumber;
    }
};

class StudentManagementSystem {
private:
    vector<Student> students;

public:
    void addStudent(const Student& s) {
        students.push_back(s);
    }

    void searchStudent(int roll) {
        bool found = false;
        for (Student& s : students) {
            if (s.getRollNumber() == roll) {
                cout << "Student found:" << endl;
                s.displayInfo();
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Student with roll number " << roll << " not found." << endl;
        }
    }

    void displayAllStudents() {
        for (Student& s : students) {
            s.displayInfo();
            cout << "---------------------" << endl;
        }
    }
};

int main() {
    StudentManagementSystem sms;

    Student s1("Ali", 101, 3.5);
    Student s2("Sara", 102, 3.8);
    Student s3 = s1;

    s1.addCourse("Math");
    s1.addCourse("Physics");

    s2.addCourse("English");

    s3.addCourse("History");

    s3.setCGPA(3.9);

    sms.addStudent(s1);
    sms.addStudent(s2);
    sms.addStudent(s3);

    cout << "All Student Records:" << endl;
    sms.displayAllStudents();

    cout << "\nSearch for roll number 102:" << endl;
    sms.searchStudent(102);

    return 0;
}
