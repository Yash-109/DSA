/*

Abstraction:

· Hiding all unnecessary details & showing only the important parts
· Implementation details are hidden, only essential information is exposed
· One of the 4 pillars of OOP (refer: 1_class_object.cpp)

Real-life Example:
- Car: You know how to drive (steering, pedals), but don't need to know engine internals
- ATM: You can withdraw money without knowing the internal mechanism

---

Achieved using ABSTRACT CLASSES:

· Abstract classes are used to provide a base class from which other classes can be derived
· They CANNOT be instantiated (cannot create objects directly)
· They are meant to be inherited by other classes
· Used to define an interface/blueprint for derived classes

---

Pure Virtual Function:

· A virtual function with NO implementation in the base class
· Syntax: virtual return_type function_name() = 0;
· Any class with at least one pure virtual function becomes an ABSTRACT class
· Derived classes MUST override all pure virtual functions (otherwise they become abstract too)

---

Key Points:

1. We cannot create objects of an abstract class
   Example: Shape s;  ❌ (Error: Shape is abstract)

2. We CAN create pointers/references of abstract class
   Example: Shape* ptr = new Circle();  ✅

3. Derived class must implement ALL pure virtual functions
   Otherwise, derived class also becomes abstract

4. Abstract classes can have:
   - Pure virtual functions (must be overridden)
   - Regular member variables
   - Regular member functions (with implementation)
   - Constructors and destructors

---

Example:
We have a class "Shape" - but creating an object of just "Shape" is meaningless
because a shape must be something specific (Circle, Rectangle, etc.)

So we make Shape an abstract class (by adding pure virtual function)
Then create derived classes: Circle, Rectangle, etc. that inherit from Shape
Now we can create objects of Circle or Rectangle, but not Shape directly

*/

#include <iostream>
#include <string>
using namespace std;

// Abstract Base Class (has at least one pure virtual function)
class Shape {
public:
    // Pure Virtual Function - no implementation in base class
    // Makes Shape an abstract class - cannot create Shape objects
    virtual void draw() = 0;  // = 0 makes it pure virtual
    
    // Regular function can exist in abstract class
    void display() {
        cout << "This is a shape" << endl;
    }
};

// Derived Class - inherits from abstract class Shape
class Circle : public Shape {
public:
    // MUST override the pure virtual function
    // Otherwise Circle will also become abstract
    void draw() {
        cout << "drawing a circle\n";
    }
};

// Another Derived Class
class Rectangle : public Shape {
public:
    // MUST override the pure virtual function
    void draw() {
        cout << "drawing a rectangle\n";
    }
};

int main() {
    // Shape s1;  ❌ Error: cannot create object of abstract class
    
    // ✅ Can create objects of derived classes
    Circle c1;
    c1.draw();      // Output: drawing a circle
    c1.display();   // Output: This is a shape (inherited function)
    
    Rectangle r1;
    r1.draw();      // Output: drawing a rectangle
    
    // ✅ Can create pointers of abstract class pointing to derived objects
    Shape* ptr1 = new Circle();
    ptr1->draw();   // Output: drawing a circle
    
    Shape* ptr2 = new Rectangle();
    ptr2->draw();   // Output: drawing a rectangle
    
    // Clean up dynamically allocated memory
    delete ptr1;
    delete ptr2;
    
    return 0;
}