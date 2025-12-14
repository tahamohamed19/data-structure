 


#include <iostream>
using namespace std;
class DoublyLinkedList {
    struct Node {
        int Data;
        Node* next;
        Node* prev;
    };

    Node* head;
public:
    DoublyLinkedList() {
        head = nullptr;
    }
    void addFront(int x) {
        Node* newnode = new Node();
        newnode->Data = x;
        newnode->next = head;
        newnode->prev = nullptr;
        if (head != nullptr) {
            head->prev = newnode;
        }
        head = newnode;
    }


void addRear(int x) {
    Node* newnode = new Node();
    newnode->Data = x;
    newnode->next = nullptr;
    if (head == nullptr) {
        newnode->prev = nullptr;
        head = newnode;
        return;
    } 
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
    temp->next = newnode;
        newnode->prev = temp ;




};

void addinside( int x , int postx) {
    Node* newnode = new Node();
    newnode->Data = x;
    Node* temp = head;
    while (temp != nullptr && temp->Data != postx) {
        temp = temp->next;
    }
    if (temp == nullptr) {
        cout << "Position not found" << endl;
        return;
    }
    newnode->next = temp->next;
    newnode->prev = temp;
    if (temp->next != nullptr) {
        temp->next->prev = newnode;
    }
    temp->next = newnode;




};






class circularLinkedList {
    struct Node {
        int Data;
        Node* next;
    };

    Node* head;
public:
    circularLinkedList() {
        head = nullptr;


}

    void addFront(int x) {
        Node* newnode = new Node();
        newnode->Data = x;
        if (head == nullptr) {
            newnode->next = newnode;
            head = newnode;
            return;
        }
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        newnode->next = head;
        temp->next = newnode;
        head = newnode;
    }
};
};



















