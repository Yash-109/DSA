/*

Inheritance:

· When properties & methods of a Base class are passed on to a Derived class
· Promotes code reusability — no need to rewrite common logic
· Derived class can add its own extra properties & methods on top of inherited ones

Syntax:
    class Derived : <mode> Base { ... };

---

Types of Inheritance:
1. Single       — one base, one derived
2. Multilevel   — A → B → C (chain)
3. Multiple     — one derived, multiple bases
4. Hierarchical — one base, multiple derived
5. Hybrid       — combination of the above

---

Mode of Inheritance (access specifier used during inheritance):

Controls how base class members are accessible in the derived class.

Protected members: accessible inside the class AND in its derived class (not outside)
                   (refer: 2_accessSpecifier.cpp)

┌─────────────┬────────────────────┬──────────────────────┬───────────────────┐
│  Base Class │ Derived: private   │ Derived: protected   │ Derived: public   │
├─────────────┼────────────────────┼──────────────────────┼───────────────────┤
│  private    │   Not Inherited    │    Not Inherited      │   Not Inherited   │
│  protected  │   private          │    protected          │   protected       │
│  public     │   private          │    protected          │   public          │
└─────────────┴────────────────────┴──────────────────────┴───────────────────┘

· private mode   — inherited members become private in derived class
· protected mode — inherited members become protected in derived class
· public mode    — inherited members keep their original access level (most common)

---

Constructor & Destructor order in Inheritance:

· Object creation  → Base constructor runs FIRST, then Derived constructor
· Object deletion  → Derived destructor runs FIRST, then Base destructor
  (refer: 6_Deconstructor.cpp)

*/

#include<iostream>
#include<string>
using namespace std;

// Base class (Parent class)
class person{
public:
    string name;
    int age;

    // Parameterized constructor
    person(string name, int age){
        this->name = name;
        this->age = age;
    }

    // Non-parameterized constructor
    person(){
        cout << "Base class constructor called" << endl;
    }
};

// Derived class (Child class) — inheriting from person using public mode
// If private mode were used: name & age (public in person) would become
// private in student — inaccessible in main() (refer mode table above)
class student : public person{
public:
    int rollno;

    // : person(name, age) — explicitly calls base class parameterized constructor
    // Required when base class has a parameterized constructor (no default available)
    // Base constructor runs first, then this derived constructor body executes
    student(string name, int age, int rollno) : person(name, age){
        this->rollno = rollno;
        cout << "Derived class constructor called" << endl;
    }

    void getInfo(){
        cout << "name: "   << name   << endl;  // inherited from person
        cout << "age: "    << age    << endl;  // inherited from person
        cout << "rollno: " << rollno << endl;  // own member
    }
    
};

int main(){
    // Constructor order: Base → Derived  (person constructor runs before student constructor)
    // Destructor order: Derived → Base   (student destructor runs before person destructor)
    // Must pass all parameters since base class has a parameterized constructor
    student s1("rahul", 20, 30);

    s1.getInfo();
    return 0;
}