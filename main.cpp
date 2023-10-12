#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Person {
public:
    Person(const string& name) : name(name) {}

    string getName() {
        return name;
    }

private:
    string name;
};

class Student : public Person {
public:
    Student(const string& name) : Person(name) {}

    void addCourse(const string& course) {
        if (courses.size() < 10) {
            courses.push_back(course);
        }
        else {
            cout << "Cannot add more than 10 courses for a student." << std::endl;
        }
    }

    void listCourses() {
        if (!courses.empty()) {
            cout << getName() << " is taking the following courses:" << endl;
            for (const string& course : courses) {
                cout << course << endl;
            }
        }
        else {
            cout << getName() << " is not currently taking any courses." << endl;
        }
    }

private:
    std::vector<string> courses;
};

class Professor : public Person {
public:
    Professor(const string& name, const string& officeLocation) : Person(name), officeLocation(officeLocation) {}

    void displayOfficeLocation() {
        cout << getName() << "'s office is located at " << officeLocation << endl;
    }

private:
    string officeLocation;
};

int main() {
    // Creating instances of Student and Professor
    Student student1("Quentin");
    Student student2("Jason");
    Professor professor1("Dr.V", "Spelman 101");

    // Adding courses for students
    student1.addCourse("CS 250");
    student1.addCourse("CS 301");
    student2.addCourse("Calculus 1");

    // Displaying information
    student1.listCourses();
    student2.listCourses();
    professor1.displayOfficeLocation();

    return 0;
}
