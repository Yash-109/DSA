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
};
int main(){
    circularLL
    return 0;
}