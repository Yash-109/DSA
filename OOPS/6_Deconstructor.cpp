/*

Destructor:

· Special method that is called automatically when an object goes out of scope or is deleted
· Used to release resources acquired during the object's lifetime
· Same name as class, preceded by ~ (tilde)
· No return type, no parameters
· Cannot be overloaded — only one destructor per class

---

Memory Management (important with pointers):

· Stack memory  — automatically freed by C++ when object goes out of scope
· Heap memory   — dynamically allocated with `new`, must be manually freed with `delete`
                  If not deleted → memory leak (heap memory is NOT auto-freed)

· Destructor is the right place to free heap-allocated memory (using delete)

---

Relation to previous topics:
· Constructor allocates heap memory with `new`    (refer: 4_Constructor.cpp)
· Destructor deallocates heap memory with `delete` ← this file
· Deep copy ensures each object has its own heap memory (refer: 5_ShallowDeepCopy.cpp)
  Without deep copy, two destructors would try to delete the same memory → undefined behaviour

*/

#include<iostream>
#include<string>
using namespace std;

class student{
public:
    string name;
    double* cgpaPtr;   // raw pointer — points to heap-allocated memory

    // Parameterized constructor — allocates heap memory (refer: 4_Constructor.cpp)
    student(string name, double cgpa){
        this->name = name;
        cgpaPtr = new double;  // allocate memory on heap
        *cgpaPtr = cgpa;       // store value via dereferencing
    }

    // Destructor — called automatically when object goes out of scope
    // Frees the heap memory allocated in the constructor to prevent memory leaks
    ~student(){
        cout << "Destructor called for: " << name << endl;
        delete cgpaPtr;   // release heap memory — stack memory is freed automatically
    }

    void getInfo(){
        cout << "name: " << name << endl;
        cout << "cgpa: " << *cgpaPtr << endl;  // dereference to get value from heap
    }
};

int main(){
    student s1("yash parmar", 8.1);
    s1.getInfo();

    student s2(s1);           // copy constructor called (shallow copy by default — see 5_ShallowDeepCopy.cpp)
    *(s2.cgpaPtr) = 9.2;      // modify s2's cgpa via dereferencing

    s1.getInfo();

    // When main() ends, destructors are called automatically (in reverse order of creation):
    //   ~student() for s2 → prints "Destructor called for: yash parmar", frees s2's heap memory
    //   ~student() for s1 → prints "Destructor called for: yash parmar", frees s1's heap memory

    return 0;
}