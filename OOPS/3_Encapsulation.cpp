/*

Encapsulation:

Encapsulation is wrapping up of data & member functions in a single unit called class.

Used in Data Hiding:
· make properties private so they can't be accessed directly from outside
· provide public setter/getter methods to control access

setter — used to SET value of a private attribute
getter — used to GET value of a private attribute

*/

#include<iostream>
#include<string>
using namespace std;

class Teacher {
private:
    // data hiding: salary is private, not directly accessible outside class
    double salary;

public:
    string name;
    string dept;
    string subject;

    // setter: controls how salary is set (can add validation here if needed)
    void setSalary(double s){
        salary = s;
    }

    // getter: controls how salary is read
    double getSalary(){
        return salary;
    }

    void getInfo(){
        cout << "name: " << name << endl;
        cout << "Department: " << dept << endl;
        cout << "Subject: " << subject << endl;
        cout << "Salary: " << salary << endl;
    }
};

int main(){
    Teacher t1;
    t1.name = "yash";
    t1.subject = "c++";
    t1.dept = "cse";

    t1.setSalary(90000);          // set via setter
    cout << t1.getSalary() << endl;   // get via getter

    t1.getInfo();

    return 0;
}
