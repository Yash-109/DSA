/*

Classes & Objects

· objects are entities in the real world
· class is like a blueprint of these entities


Access Modifiers:

private    in c++ bydefault attribute methods are private 
data & methods accessible inside class

public
data & methods accessible to everyone

protected
data & methods accessible inside class & to its
derived class


4 Pillars of OOPS:

1) Encapsulation
2) Abstraction
3) Inheritance
4) Polymorphism

1) Encapsulation:
Encapsulation is wrapping up of data & member functions in a single unit called class.

Encapsulation used in Data hiding 
example:  make property private which should not be accessed 


Constructor:

Special method invoked automatically at time of object creation. Used for Initialisation.

· Same name as class
· Constructor doesn't have a return type
. Only called once (automatically), at object creation
· Memory allocation happens when constructor is called   
by above point if user dont make constructoe for anyclass then c++ compiler automatically make constructior afther that memory allocation get done

class is only blueprint it doesn't occupy memory        Objects occupy memory
so memory allocation done by constructor not classs

3 tpe of constructor:
1. non-parameterized 2. paramterized and 3. copy constructor
for more than one constructor , they must be differnt form type or by paramter number
above concept called constructpr overloading which is in polymorphism

this is a special pointer in C++ that points to the current object.
this->prop is same as *(this).prop

this is nothing but automatic created pointer whihc always point to object whihc is getting called
*this = object
(*this).prop = this->prop

Copy Constructor:
Special Constructor (default) used to copy properties of one object into another.
if we dont make copy constructor then c++ make default constructor by own

*/

#include<iostream>
#include<string>
using namespace std;

class Teacher {
private:
   // this is data hiding
   double salary;  // we cant access salary otside this class 

public:

    //Properties
    string name;
    string dept;
    string subject;

    // parameterized 
    Teacher(string n, string d, string s,double sal ){
        name = n;
        dept = d;
        subject = s;
        salary = sal;
    }

    /* Teacher(string name, string department, string subject,double salary ){
        this->name = name;   // when want to show object property we use this  here lett name = object's name  and the right sided name is paramter of function
        this->dept = department;
        this->subject = subject;
        this->salary = salary;
    }    */

    // non-parametred constructor
    Teacher(){
        cout<<"COnstructor called"<<endl;
    }

    // copy constructor
    Teacher(Teacher &orgObj){  // pass by refernce
        cout<<" i am custom copy constructor";
        this->name = orgObj.name;
        this->dept = orgObj.dept;
        this->subject = orgObj.subject;
        this->salary = orgObj.salary ;


    }


    //Methods = functions          memebr functions = class methods
    void changeDept(string newDept){
        dept = newDept;
    }

    // setter     used to set value of private attributes
    void setSalary(double s){
        salary = s;
    }

    //getter      used to get value of private attributes
    double getSalary(){
        return salary;
    }

    void getInfo(){
        cout<< "name: "<<name<<endl;
        cout<< "Department: "<<dept<<endl;
        cout<< "Subject: "<<subject<<endl;
        cout<< "salary "<<salary<<endl;

    }
};


int main(){
    Teacher t1;
    t1.name = "yash";
    t1.subject = "c++";
    t1.dept = "cse";
    t1.setSalary(90000);
    cout<<t1.getSalary()<<endl<<endl;
    t1.getInfo();
    cout<<endl;

    // instead above we can use construcotr:
    Teacher t2("yashhh","ce","maths",85000);
    t2.getInfo();
    cout<<endl<<endl;

    Teacher t3(t2);  // custom copy-constructor invoked
    t3.getInfo(); // same as t2 

    // if we comment out copy construtor then default copy constructor will get invoked

    
    
    return 0;
}
