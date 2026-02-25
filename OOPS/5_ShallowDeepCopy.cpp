/*

Shallow Copy vs Deep Copy:

· Both are types of Copy Constructors (refer: 4_Constructor.cpp)

Shallow Copy:
· Copies all member values as-is, including pointer addresses
· Both objects end up pointing to the SAME memory location on the heap
· Problem: changing data through one object affects the other (shared memory)
· C++ default copy constructor performs a shallow copy

Deep Copy:
· Copies member values AND allocates NEW memory for pointer members
· Each object gets its OWN separate copy of heap-allocated data
· Changing data in one object does NOT affect the other
· Must be explicitly defined by the programmer

---

When to use Deep Copy:
· Whenever a class has pointer members (dynamically allocated memory)
· To avoid unintended data sharing between objects

*/

#include<iostream>
#include<string>
using namespace std;
 
class student{
public:  
    string name;
    double* cgpaPtr;   // raw pointer — points to heap-allocated memory

    // Parameterized constructor
    // this-> used because parameter name is same as member variable name (refer: 4_Constructor.cpp)
    student(string name, double cgpa){
        this->name = name;
        cgpaPtr = new double;  // allocate memory on heap for cgpa
        *cgpaPtr = cgpa;       // dereference pointer to store the value
    }

    // -----------------------------------------------------------------------
    // SHALLOW COPY CONSTRUCTOR (commented out — shows the problem)
    // -----------------------------------------------------------------------
    // student(student &obj){
    //     this->name = obj.name;
    //     this->cgpaPtr = obj.cgpaPtr;  // copies pointer address — both point to SAME heap memory
    // }
    //
    // Problem with shallow copy:
    //   s1.cgpaPtr ──┐
    //                ├──► [ heap: 8.1 ]   ← single shared memory block
    //   s2.cgpaPtr ──┘
    //
    // Changing *(s2.cgpaPtr) = 9.2 also changes s1's cgpa!
    //
    // Output (shallow copy):
    //   name: yash parmar  cgpa: 8.1   ← s1 before change
    //   name: yash parmar  cgpa: 9.2   ← s1 after s2's change (unintended!)

    // -----------------------------------------------------------------------
    // DEEP COPY CONSTRUCTOR (active — correct approach)
    // -----------------------------------------------------------------------
    student(student &obj){
        this->name = obj.name;
        *cgpaPtr = *obj.cgpaPtr;   // copy the VALUE at the address, not the address itself
    }
    //
    // Effect with deep copy:
    //   s1.cgpaPtr ──► [ heap: 8.1 ]   ← s1's own memory block
    //   s2.cgpaPtr ──► [ heap: 8.1 ]   ← s2's own separate memory block
    //
    // Changing *(s2.cgpaPtr) = 9.2 only changes s2 — s1 is unaffected.
    //
    // Output (deep copy):
    //   name: yash parmar  cgpa: 8.1   ← s1 before change
    //   name: yash parmar  cgpa: 8.1   ← s1 after s2's change (unchanged — correct!)

    void getInfo(){
        cout << "name: " << name << endl;
        cout << "cgpa: " << *cgpaPtr << endl;  // dereference to get value from heap
    }
};

int main(){
    student s1("yash parmar", 8.1);
    s1.getInfo();                      // prints s1's original data

    student s2(s1);                    // copy constructor is called here
    *(s2.cgpaPtr) = 9.2;              // modify s2's cgpa via dereferencing

    s1.getInfo();   // with shallow copy: cgpa becomes 9.2 (shared memory problem)
                    // with deep copy:    cgpa stays 8.1  (independent memory — correct)

    return 0;
}
