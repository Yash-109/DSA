/*

Polymorphism:

· Polymorphism = ability of objects to take on different forms or behave in different
                 ways depending on the context in which they are used
· One of the 4 pillars of OOP (refer: 1_class_object.cpp)

Two types:
1. Compile Time Polymorphism (Static Polymorphism)
2. Runtime Polymorphism (Dynamic Polymorphism)

---

1. COMPILE TIME POLYMORPHISM:

· Resolved at compile time — compiler decides which function to call
· Faster than runtime polymorphism (no overhead during execution)

Three types:
a) Constructor Overloading    — multiple constructors with different parameters
b) Function Overloading       — same function name, different parameters (type/count)
c) Operator Overloading       — custom behavior for operators (+, -, ==, etc.)

---

Constructor Overloading (refer: 4_Constructor.cpp):
· Same class has multiple constructors
· Differ by number or type of parameters
· Compiler selects based on arguments provided at object creation

Example:
    Student() { }                          // non-parameterized
    Student(string name) { }               // parameterized

Function Overloading:
· Same function name within the same class
· Must differ by:
  - Number of parameters
  - Type of parameters
  - Order of parameters
· Return type alone CANNOT differentiate overloaded functions

Example:
    void show(int x) { }
    void show(char ch) { }

Operator Overloading:
· Define custom behavior for operators when used with class objects
· Syntax: return_type operator symbol (parameters) { }
· Common operators: +, -, *, /, ==, <<, >>, ++, --, etc.
· Example: if we have two string objects, we can define what string a + string b means

Note: Operator overloading is an advanced topic — just understand the concept for now

---

2. RUNTIME POLYMORPHISM:

· Resolved at runtime — decision made during program execution
· Requires Inheritance
· Uses pointers/references to base class

Two types:
a) Function Overriding        — child class redefines parent's function
b) Virtual Functions          — parent function marked 'virtual', child overrides it

---

Function Overriding:
· Parent & Child both have the same function signature (name + parameters)
· Child class provides its own implementation
· Parent function is said to be "overridden"
· Requires inheritance (refer: 7_Inheritance.cpp)

Virtual Functions:
· Declared with 'virtual' keyword in base class
· Tells compiler: "This function is expected to be overridden in derived classes"
· Enables dynamic dispatch — correct function called based on actual object type (not pointer type)
· Called at runtime (dynamic binding)

Why use virtual?
· Without virtual: Parent pointer calls Parent's version (even if object is Child)
· With virtual:    Parent pointer calls Child's version (if object is Child)

Syntax:
    virtual return_type function_name(parameters) { }

*/

#include<iostream>
#include<string>
using namespace std;

// ============================================================================
// 1. COMPILE TIME POLYMORPHISM
// ============================================================================

// -----------------------------
// a) Constructor Overloading
// -----------------------------

class Student {
public:
    string name;

    // Non-parameterized constructor
    Student() {
        cout << "non-parameterized constructor called" << endl;
    }

    // Parameterized constructor (overloaded)
    Student(string name) {
        this->name = name;
        cout << "parameterized constructor called" << endl;
    }
};

// -----------------------------
// b) Function Overloading
// -----------------------------

class Print {
public:
    // Function show() overloaded with different parameter types

    void show(int x) {
        cout << "int : " << x << endl;
    }

    void show(char ch) {
        cout << "char : " << ch << endl;
    }

    // Can also overload by number of parameters
    void show(int x, int y) {
        cout << "int x, int y : " << x << ", " << y << endl;
    }
};

// -----------------------------
// c) Operator Overloading (concept only — not implemented here)
// -----------------------------

// Example syntax for operator overloading:
// class Complex {
//     int real, imag;
// public:
//     Complex operator + (Complex &obj) {
//         Complex result;
//         result.real = real + obj.real;
//         result.imag = imag + obj.imag;
//         return result;
//     }
// };

// ============================================================================
// 2. RUNTIME POLYMORPHISM
// ============================================================================

// -----------------------------
// a) Function Overriding (without virtual)
// -----------------------------

class Parent {
public:
    void getInfo() {
        cout << "parent class" << endl;
    }

    // Virtual function — marked with 'virtual' keyword
    // Allows derived class to override and enables dynamic dispatch
    virtual void hello() {
        cout << "hello from parent" << endl;
    }
};

class Child : public Parent {
public:
    // Function overriding — same signature as Parent's getInfo()
    void getInfo() {
        cout << "child class" << endl;
    }

    // Overriding parent's virtual function
    void hello() {
        cout << "hello from child" << endl;
    }
};

// ============================================================================
// MAIN FUNCTION
// ============================================================================

int main() {
    cout << "========== COMPILE TIME POLYMORPHISM ==========" << endl;
    cout << "\n--- Constructor Overloading ---" << endl;
    Student s1;                     // calls non-parameterized constructor
    Student s2("tony stark");       // calls parameterized constructor

    cout << "\n--- Function Overloading ---" << endl;
    Print p1;
    p1.show(101);      // calls show(int)
    p1.show('&');      // calls show(char)
    p1.show(10, 20);   // calls show(int, int)

    cout << "\n========== RUNTIME POLYMORPHISM ==========" << endl;
    cout << "\n--- Function Overriding ---" << endl;
    Parent p;
    p.getInfo();       // calls Parent's getInfo() → prints "parent class"

    Child c;
    c.getInfo();       // calls Child's getInfo() → prints "child class"

    cout << "\n--- Virtual Functions ---" << endl;
    // Without virtual: would call Parent's hello() even if object is Child
    // With virtual: calls Child's hello() because object type is Child
    Parent p2;
    p2.hello();        // calls Parent's hello() → prints "hello from parent"

    Child c2;
    c2.hello();        // calls Child's hello() → prints "hello from child"

    // Advanced: Virtual functions enable polymorphism via base class pointers
    cout << "\n--- Virtual Function with Pointer ---" << endl;
    Parent* ptr;       // base class pointer
    Child c3;
    ptr = &c3;         // pointer to Child object
    
    // Because hello() is virtual, this calls Child's version (dynamic binding)
    ptr->hello();      // → prints "hello from child"

    // getInfo() is NOT virtual, so this calls Parent's version (static binding)
    ptr->getInfo();    // → prints "parent class"

    return 0;
}