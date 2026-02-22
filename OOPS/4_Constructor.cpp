/*

Constructor:

Special method invoked automatically at time of object creation. Used for Initialisation.

· Same name as class
· No return type
· Called once automatically at object creation
· Memory allocation happens when constructor is called
  (if user doesn't define one, C++ compiler creates a default constructor)

class is only blueprint — it doesn't occupy memory
Objects occupy memory — memory is allocated when constructor is called

3 types of constructors:
1. Non-parameterized
2. Parameterized
3. Copy Constructor

Constructor Overloading:
For more than one constructor, they must differ by parameter type or count.
(this concept is part of Polymorphism)

---

this pointer:

· Special pointer automatically created by C++, always points to the current object
· this->prop  is same as  (*this).prop
· *this = the object itself
· Used when parameter name is same as member variable name to avoid ambiguity

---

Copy Constructor:

· Special constructor used to copy properties of one object into another
· Passed by reference to avoid infinite recursion
· If not defined, C++ creates a default copy constructor automatically

*/

#include<iostream>
#include<string>
using namespace std;

class Teacher {
private:
    double salary;

public:
    string name;
    string dept;
    string subject;

    // 1. Non-parameterized constructor
    Teacher(){
        cout << "Constructor called" << endl;
        salary = 0.0;
    }

    // 2. Parameterized constructor
    // this-> used because parameter names are same as member variable names
    Teacher(string name, string dept, string subject, double salary){
        this->name = name;       // left: object's member | right: parameter
        this->dept = dept;
        this->subject = subject;
        this->salary = salary;
    }

    // 3. Copy Constructor — pass by reference to avoid infinite recursion
    Teacher(Teacher &orgObj){
        cout << "Copy constructor called" << endl;
        this->name = orgObj.name;
        this->dept = orgObj.dept;
        this->subject = orgObj.subject;
        this->salary = orgObj.salary;
    }

    void setSalary(double s){ salary = s; }
    double getSalary(){ return salary; }

    void getInfo(){
        cout << "name: " << name << endl;
        cout << "Department: " << dept << endl;
        cout << "Subject: " << subject << endl;
        cout << "Salary: " << salary << endl;
    }
};

int main(){
    // non-parameterized constructor
    Teacher t1;
    t1.name = "yash";
    t1.dept = "cse";
    t1.subject = "c++";
    t1.setSalary(90000);
    t1.getInfo();
    cout << endl;

    // parameterized constructor
    Teacher t2("yashhh", "ce", "maths", 85000);
    t2.getInfo();
    cout << endl;

    // copy constructor — copies t2 into t3
    Teacher t3(t2);
    t3.getInfo();   // same output as t2

    // if copy constructor is commented out, C++ default copy constructor is used

    return 0;
}
