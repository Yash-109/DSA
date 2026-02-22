/*

Classes & Objects

· objects are entities in the real world
· class is like a blueprint of these entities

· class does NOT occupy memory — it is just a blueprint
· objects occupy memory

4 Pillars of OOPS:
1) Encapsulation
2) Abstraction
3) Inheritance
4) Polymorphism

*/

#include<iostream>
#include<string>
using namespace std;

class Teacher {
public:
    // Properties (member variables)
    string name;
    string dept;
    string subject;

    // Methods (member functions)
    void getInfo(){
        cout << "name: " << name << endl;
        cout << "Department: " << dept << endl;
        cout << "Subject: " << subject << endl;
    }
};

int main(){
    Teacher t1;         // object creation — memory allocated here
    t1.name = "yash";
    t1.subject = "c++";
    t1.dept = "cse";
    t1.getInfo();

    return 0;
}
