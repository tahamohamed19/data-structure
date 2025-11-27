#include <iostream>
using namespace std ;

class queue{
     int head ;
     int tail ;
     int size =  6 ;
     int *arr ;
public :
    queue(int size) {
        arr =new int[size];
        tail = -1 ;
        head = -1 ;

    } 
    void enqueue (int num) {
        if (tail == size -1) {
            cout <<"the queue is full" ;

        }else {
                arr[tail++] = num ;
                    cout <<"array was added succesfully" << endl;
        ;}
    }
    int dequeue (int num){
        if(head == size-1){
            cout<<"the queue isnt empty" ;
            return 0;
        }else {
        int t = head ; 
        head++;
        return t;
        }
    }    
};

int main () {
    queue q(4) ;
    q.enqueue(4);
    q.enqueue(4) ;
    q.enqueue(4);

    q.dequeue(4);
    cout <<"array was deleted succesfully" << endl;

    return 0;
}