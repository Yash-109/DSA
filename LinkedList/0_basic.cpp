#include<iostream>
using namespace std;

class Node {   // this individual node calss can have mant object like in example 1, 2, 3,..
public:
    int data;
    Node* next;  // always store address of next node

    Node(int val){  // constructor
        data = val;
        next = NULL;
    } 
};

class List {
    Node* head;  // not declared as public so by default private
    Node* tail;
    
public:
    List(){
        head = tail = NULL;
    }


    // 1.
    void push_front(int val){   

        // create new Node
        Node* newNode = new Node(val);  // this is dynamic declaration
       // Node* newNode(val); // static declaration so can't use or call in main function


       if(head == NULL){
        // if LL is empty simply head and tail point to newNode
        head = tail = newNode;
        return;
       }

       else{
        // if non empty first newNodes's next ptr will point to current head 
        //   here current head will always be first node in LL
        newNode->next = head;   // (it is equal to (*newNode).next = head)

        // then change the head
        head = newNode;
       }
    } 

    //2.
    void push_back(int val){
        Node* newNode = new Node(val);

        if(head == NULL){
            head = tail = newNode;
        }

        else{
            tail->next = newNode;
            tail = newNode;
        }

    }

    //3.
    void pop_front(){
        if(head == NULL){
            cout<< "LL is empty\n";
            return;
        }

        else{
            Node* temp = head;
            head = head->next;
            temp->next = NULL;
            
            delete temp; // deleting the "node" that was dynamically allocated earlier 
            // temp → stack pointer
            // *temp (the node it points to) → heap memory            
        }
    }

    //4.
    void pop_back(){
        if(head == NULL){
            cout<<"LL is empty\n";
            return;
        }

        Node* temp = head;
        while(temp->next != tail){
            temp = temp->next;
        }

        temp->next = NULL;
        delete tail;  // here we are deleting the data which is in tail node
        tail = temp;  // assigning value in tail node
    }

    void printLL(){
        Node* temp = head;

        while(temp!=NULL){
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }
};


int main(){
    List ll;
    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);

    ll.printLL(); // 3 -> 2 -> 1 -> NULL

    ll.push_back(4);
    ll.printLL(); // 3 -> 2 -> 1 -> 4 -> NULL
  
    ll.pop_front();
    ll.printLL();  // 2 -> 1 -> 4 -> NULL

    ll.pop_back();
    ll.printLL(); // 2 -> 1 -> NULL
    return 0;
}