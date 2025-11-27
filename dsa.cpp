#include <iostream>
using namespace std;




class Linkelist{

    struct Node{
        int Data;
        Node *next;
    };

    Node *head;
    

    public:
    Linkelist(){
        head = NULL;
    }


    void addFront(int x){
        Node *newnode;
        if (head == NULL){
            newnode -> Data = x;
            head = newnode;
            newnode -> next = NULL;
        }else{
            newnode -> next = head;
            newnode -> Data = x;
            head = newnode;

        }
        
    }


    void addRear(int x){
        Node *newnode;
        Node *end;
        end = head;

        while (end -> next != NULL){
            end = end -> next;
        }

        newnode -> Data = x;
        end -> next = newnode;
        newnode -> next = NULL;

        

    };

  void insertbetween(int x, int index){
        Node *p;
        Node *newnode;
        p = head;
        int c = 1;
        while (p -> next != NULL && index != c)
        {
           p = p -> next;
           c++;
        }
        newnode->Data=x;
        newnode -> next = p -> next;
        p -> next = newnode;

}

void addbefore(int value ,int x){
    Node *newnode;
    Node *p;
     p = head;

        while (p->next->Data != value )
        {
            p = p->next;
        }
        newnode->Data = x;
        newnode->next = p->next;
        p->next=newnode;
        


}
};


int main(){

    // int x = 5;
    // int* y = &x;

    // cout<< x <<endl;
    // cout<< y <<endl;
    // cout<< &x <<endl; // y = &x
    // cout<< &y <<endl;
    // cout<< *y <<endl; // *y = x




}