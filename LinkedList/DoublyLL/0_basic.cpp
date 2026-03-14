#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val){
        data = val;
        next = prev = nullptr;
    }
};

class DoublyList{
    Node* head;
    Node* tail;

public: 
    DoublyList(){
        head = tail = nullptr;
    }

    // 1.
    void push_front(int val){
        Node* newNode = new Node(val);

        if(head == nullptr){
            head = tail = newNode;
        }
        else{
            newNode->next = head;
            head->prev = newNode;
            head = newNode; 
        }
    }

    //2
    void print(){
         Node* temp = head;

         while(temp != nullptr){
            cout<< temp->data<<" <=> ";
            temp = temp->next;
         }
         cout<<"NULL\n";
    }

     //3.
    void push_back(int val){
        Node* newNode = new Node(val);
        if(head == nullptr){
            head = tail = newNode;
        }
        else{
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    //4.
    void pop_front(){
        if(head == nullptr){
            cout<<"DoublyLL is Empty.";
            return;
        }
        Node* temp = head;
        head = head->next;

        // side case for list having only one node
        // check needed because after removing the only node, head becomes nullptr and accessing head->prev would cause a crash
        if(head!=nullptr){
            head->prev = nullptr;
        }

        temp->next = nullptr;
        delete temp;
    }

    //5.
    void pop_back()
    {
        if(head == nullptr){
            cout<<"DoublyLL is empty.";
            return;
        }
        Node* temp = tail;
        tail = tail->prev;

        // if list has only 1 node, for that if condition
        if(tail!=nullptr){
            tail->next = nullptr;
        }

        temp->prev = nullptr;
        delete temp;
    }


};

int main(){
    DoublyList dll;
    dll.push_front(1);
    dll.push_front(2);
    dll.print();  // 2 <=> 1 <=> NULL

    dll.push_back(3);
    dll.push_back(4);
    dll.print(); // 2 <=> 1 <=> 3 <=> 4 <=> NULL

    dll.pop_front();
    dll.print(); // 1 <=> 3 <=> 4 <=> NULL

    dll.pop_back();
    dll.print(); // 1 <=> 3 <=> NULL



    return 0;
}