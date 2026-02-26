/*

Static Keyword:

The 'static' keyword changes the lifetime and scope of variables and objects.

---

1. STATIC VARIABLES IN FUNCTIONS:

· Declared inside a function
· Created and initialized ONLY ONCE during the first function call
· Retains its value between function calls (not destroyed when function ends)
· Lifetime: entire program execution
· Scope: limited to the function where declared

Normal variable vs Static variable:
- Normal: created and destroyed every function call
- Static: created once, persists across all function calls

---

2. STATIC VARIABLES IN CLASSES:

· Created and initialized ONLY ONCE, no matter how many objects are created
· SHARED by ALL objects of the class
· All objects access the same memory location
· Must be defined outside the class (initialized globally)

Normal member variable vs Static member variable:
- Normal: each object has its own copy
- Static: all objects share one copy

---

3. STATIC OBJECTS:

· Created once and destroyed at the end of the program (not when scope ends)
· Destructor is called at program termination, not when scope ends

Normal object vs Static object:
- Normal: destructor called when scope ends
- Static: destructor called when program ends

---

4. STATIC FUNCTIONS (not shown in this example):

· Can be called without creating an object: ClassName::functionName()
· Can only access static members of the class
· No 'this' pointer (since no object is associated)

*/

#include<bits/stdc++.h>
using namespace std;

// Example 1: Static variable in function
void fun(){
    static int x = 0;  // initialized ONLY ONCE (first call only)
                       // on subsequent calls, x retains previous value
    cout<< "x : "<< x << endl;
    x++;  // increment persists across function calls
}

// Example 2: Class with normal (non-static) member variable
// Each object has its own copy of 'a'
class A{
public:
    int a;  // normal member variable - each object has separate copy

    void incrementX(){
        a = a+1;
    }
};

// Example 3: Class to demonstrate static object behavior
class ABC{
public:
    ABC(){
        cout<< "constructor"<<endl;
    }

    ~ABC(){
        cout<< "Destructor"<<endl;
    }
};

int main(){

    // ===== EXAMPLE 1: Static Variable in Function =====
    cout << "--- Static Variable in Function ---" << endl;
    fun(); // Output: x : 0  (x initialized to 0, then incremented to 1)
    fun(); // Output: x : 1  (x NOT reinitialized, still 1, then incremented to 2)
    fun(); // Output: x : 2  (x still 2, then incremented to 3)
    // x retains its value between function calls!

    cout << endl;

    // ===== EXAMPLE 2: Normal Variables in Class =====
    cout << "--- Normal Variables (each object has own copy) ---" << endl;
    A obj1;
    A obj2;

    obj1.a = 100;  // obj1's 'a' is set to 100
    obj2.a = 200;  // obj2's 'a' is set to 200 (separate copy)
    cout << obj1.a << endl;  // Output: 100 (each object has its own 'a')

    cout << endl;

    // ===== EXAMPLE 3: Static Object vs Normal Object =====
    cout << "--- Static Object Behavior ---" << endl;
    
    // NORMAL OBJECT (commented out for comparison):
    // if(true){
    //     ABC obj;  // normal object
    //     
    //     Output order:
    //     1. constructor
    //     2. Destructor  ← destructor called when scope ends (at closing brace)
    //     3. end of main function
    // }

    // STATIC OBJECT:
    if(true){
        static ABC obj3;  // static object
        
        // Output order:
        // 1. constructor  ← object created when this line executes
        // 2. end of main function
        // 3. Destructor  ← destructor called at program end (not at scope end!)
    }
    // Note: obj3's destructor is NOT called here (at closing brace)
    // It will be called when main() ends

    cout<< "end of main function"<<endl;

    return 0;
    // obj3's destructor is called HERE (when program exits)

}