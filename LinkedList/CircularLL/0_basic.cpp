#include<iostream>
using namespace std;


class Node{
public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = nullptr;
    }
};

class circularList{
    Node* head;
    Node* tail;


public:

    circularList(){
        head = nullptr;
        tail = nullptr;
    }

    //1.
    void inserAtHead(int val){
        Node* newNode = new Node(val);
        if(head == nullptr){
            head = tail = newNode;
            tail->next = head;  // bcz it is circular LL
        }
        else{
            newNode->next = head;
            head = newNode;
            tail->next = head;
        }
    }

    //2. 
    void print(){
        if(head == nullptr){
            cout<<"Linked list is empty";
            return;
        }

        cout<< head -> data << "->";
        Node* temp = head->next;

        while(temp != head){  // in normal ll : temp != null
            cout<<temp->data << "->";
            temp = temp->next;
        }
        cout<<temp->data << endl;
    }

    //3.
    void insertAtTail(int val){
        Node* newNode = new Node(val);
        if(head == nullptr){
            head = tail = newNode;
            tail->next = head;  // bcz it is circular LL
        }
        else{
            newNode->next = head;
            tail->next = newNode;
            tail = newNode;
        }
    }

    //4.
    void deletatHead(){
        // if empty
        if(head == nullptr){
            cout<<"Empty LL.";
            return;
        }

        // if single node in ll
        if(head == tail){
            delete head;
            head = tail =nullptr;
        }

        // if more than one node
        Node* temp = head;
        
        head = head->next;
        tail->next = head;

        temp->next = nullptr;
        delete temp;
   }

   //5. 
   void deleteatTail(){
        // if empty
        if(head == nullptr){
            cout<<"Empty LL.";
            return;
        }

        // if single node in ll
        if(head == tail){
            delete head;
            head = tail =nullptr;
        }

        // if multiple nodes
        Node* temp = tail;

        Node*prev  = head;

        while(prev->next != tail){
            prev = prev->next;
        }

        tail = prev;
        tail->next = head;

        temp->next = nullptr;
        delete temp;
   }
};
int main(){
    circularList cll;

    cll.inserAtHead(1);
    cll.inserAtHead(2);
    cll.inserAtHead(3);

    cll.print(); // 3->2->1->3

    cll.insertAtTail(4); 

    cll.print(); // 3->2->1->4->3

    cll.deletatHead();

    cll.print(); // 2->1->4->2

    cll.deleteatTail();

    cll.print(); // 2->1->2
    
    return 0;
}