/*

Access Modifiers (Access Specifiers):

private    — in C++, by default all attributes & methods are private
               data & methods accessible inside the class only

public     — data & methods accessible to everyone (inside & outside class)

protected  — data & methods accessible inside class & to its derived class
               (used in Inheritance)

*/

#include<iostream>
#include<string>
using namespace std;

class Teacher {
private:
    double salary;   // only accessible inside class

public:
    string name;
    string dept;
    string subject;

    void setSalary(double s){
        salary = s;   // private member accessed inside class — allowed
    }

    double getSalary(){
        return salary;
    }
};

int main(){
    Teacher t1;
    t1.name = "yash";    // public — accessible directly
    t1.dept = "cse";
    t1.subject = "c++";

    // t1.salary = 90000;  // ERROR: private — not accessible outside class

    t1.setSalary(90000);         // correct way: use public method
    cout << t1.getSalary() << endl;

    return 0;
}
