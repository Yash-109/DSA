/*

Types of Inheritance:

(refer: 7_Inheritance.cpp for basic concepts)

---

1. Single Inheritance:
   · One derived class inherits from one base class
   · Structure: Parent → Child
   · Example: Person → Student

2. Multilevel Inheritance:
   · Derived class becomes base class for another class (chain)
   · Structure: Grandparent → Parent → Child
   · Example: Person → Student → GradStudent

3. Multiple Inheritance:
   · One derived class inherits from multiple base classes
   · Structure: Parent1 + Parent2 → Child
   · Example: Student + Teacher → TA (Teaching Assistant)

4. Hierarchical Inheritance:
   · One base class, multiple derived classes
   · Structure: Parent → Child1, Parent → Child2
   · Example: Person → Student, Person → Teacher

5. Hybrid Inheritance:
   · Combination of two or more types of inheritance
   · Structure: Mix of above patterns
   · Example: Person → Student/Teacher, then Student + Teacher → TA

---

Syntax for Multiple Inheritance:
    class Derived : public Base1, public Base2 { ... };

---

Diamond Problem (in Multiple Inheritance):
· Occurs when a class inherits from two classes that share a common base
· Can cause ambiguity — which base class member to use?
· Solved using virtual inheritance (advanced topic)

*/

#include<iostream>
#include<string>
using namespace std;

// ============================================================================
// 1. SINGLE INHERITANCE
//    Person → Student
// ============================================================================

class Person {
public:
    string name;
    int age;

    Person() {}  // default constructor

    Person(string name, int age) {
        this->name = name;
        this->age = age;
    }
};

class Student : public Person {
public:
    int rollno;

    Student(string name, int age, int rollno) : Person(name, age) {
        this->rollno = rollno;
    }

    void getInfo() {
        cout << "name: " << name << endl;
        cout << "age: " << age << endl;
        cout << "rollno: " << rollno << endl;
    }
};

// ============================================================================
// 2. MULTILEVEL INHERITANCE
//    Person → Student → GradStudent (chain of inheritance)
// ============================================================================

// GradStudent inherits from Student, which inherits from Person
// GradStudent gets properties: name, age (from Person) + rollno (from Student) + researchArea (own)
class GradStudent : public Student {
public:
    string researchArea;

    GradStudent(string name, int age, int rollno, string researchArea)
        : Student(name, age, rollno) {
        this->researchArea = researchArea;
    }

    void getInfo() {
        cout << "name: " << name << endl;           // from Person (grandparent)
        cout << "age: " << age << endl;             // from Person (grandparent)
        cout << "rollno: " << rollno << endl;       // from Student (parent)
        cout << "researchArea: " << researchArea << endl;  // own member
    }
};

// ============================================================================
// 3. MULTIPLE INHERITANCE
//    Student + Teacher → TA (Teaching Assistant)
// ============================================================================

class Teacher : public Person {
public:
    string subject;
    double salary;

    Teacher() {}  // default constructor

    Teacher(string name, int age, string subject, double salary)
        : Person(name, age) {
        this->subject = subject;
        this->salary = salary;
    }

    void getInfo() {
        cout << "name: " << name << endl;
        cout << "age: " << age << endl;
        cout << "subject: " << subject << endl;
        cout << "salary: " << salary << endl;
    }
};

// TA inherits from both Student AND Teacher
// Syntax: class Derived : public Base1, public Base2
class TA : public Student, public Teacher {
public:
    // TA has access to:
    // - from Student: name, age, rollno
    // - from Teacher: name, age, subject, salary
    // Note: both Student and Teacher inherit from Person, so name & age exist twice
    //       Must use scope resolution (Student::name or Teacher::name) to avoid ambiguity

    TA(string name, int age, int rollno, string subject, double salary)
        : Student(name, age, rollno), Teacher(name, age, subject, salary) {
        // Both base class constructors called
    }

    void getInfo() {
        // Using Student's inherited members (from Person)
        cout << "name: " << Student::name << endl;        // specify which 'name'
        cout << "age: " << Student::age << endl;          // specify which 'age'
        cout << "rollno: " << rollno << endl;             // from Student
        cout << "subject: " << subject << endl;           // from Teacher
        cout << "salary: " << salary << endl;             // from Teacher
    }
};

// ============================================================================
// 4. HIERARCHICAL INHERITANCE (demonstrated above)
//    Person is the base class, both Student and Teacher inherit from it
//    Person → Student
//    Person → Teacher
// ============================================================================

int main() {
    cout << "===== 1. SINGLE INHERITANCE =====" << endl;
    Student s1("tony stark", 20, 101);
    s1.getInfo();
    cout << endl;

    cout << "===== 2. MULTILEVEL INHERITANCE =====" << endl;
    GradStudent g1("bruce banner", 25, 201, "quantum physics");
    g1.getInfo();
    cout << endl;

    cout << "===== 3. MULTIPLE INHERITANCE =====" << endl;
    TA t1("peter parker", 22, 301, "engineering", 50000);
    t1.getInfo();
    cout << endl;

    cout << "===== 4. HIERARCHICAL INHERITANCE =====" << endl;
    cout << "Student and Teacher both inherit from Person (shown in class definitions)" << endl;
    cout << endl;

    cout << "===== 5. HYBRID INHERITANCE =====" << endl;
    cout << "TA class demonstrates hybrid inheritance:" << endl;
    cout << "- Hierarchical: Person → Student, Person → Teacher" << endl;
    cout << "- Multiple: Student + Teacher → TA" << endl;

    return 0;
}