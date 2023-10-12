#include <iostream>
#include <string>
#include <vector>

class Person {
public:
    Person(const std::string& name) : name(name) {}

    std::string getName() const {
        return name;
    }

private:
    std::string name;
};

class Student : public Person {
public:
    Student(const std::string& name) : Person(name) {}

    void addCourse(const std::string& course) {
        if (courses.size() < 10) {
            courses.push_back(course);
        }
        else {
            std::cout << "Cannot add more than 10 courses for a student." << std::endl;
        }
    }

    void listCourses() const {
        if (!courses.empty()) {
            std::cout << getName() << " is taking the following courses:" << std::endl;
            for (const std::string& course : courses) {
                std::cout << course << std::endl;
            }
        }
        else {
            std::cout << getName() << " is not currently taking any courses." << std::endl;
        }
    }

private:
    std::vector<std::string> courses;
};

class Professor : public Person {
public:
    Professor(const std::string& name, const std::string& officeLocation) : Person(name), officeLocation(officeLocation) {}

    void displayOfficeLocation() const {
        std::cout << getName() << "'s office is located at " << officeLocation << std::endl;
    }

private:
    std::string officeLocation;
};

int main() {
    // Creating instances of Student and Professor using pointers
    Person* student1 = new Student("Alice");
    Person* student2 = new Student("Bob");
    Person* professor1 = new Professor("Dr. Smith", "Room 101");

    // Adding courses for students
    static_cast<Student*>(student1)->addCourse("Math 101");
    static_cast<Student*>(student1)->addCourse("Physics 101");
    static_cast<Student*>(student2)->addCourse("History 101");

    // Displaying information
    static_cast<Student*>(student1)->listCourses();
    static_cast<Student*>(student2)->listCourses();
    static_cast<Professor*>(professor1)->displayOfficeLocation();

    // Clean up memory
    delete student1;
    delete student2;
    delete professor1;

    return 0;
}
