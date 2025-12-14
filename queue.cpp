class Queue{

    int *arr;
    int size;
    int cap;
    int front;

    public:

    Queue(int c){
        cap = c;
        size = 0;
        front = 0;
        arr = new int[cap];

    }


    void enqueue(int x){
        if(size == cap){
            cout << "Overflow" << endl;
        }else{
            int rear = (front + size) % cap;
            arr[rear] = x;
            size++;
        }
    }


    int dequeue(){
        if (size == 0){
            cout << "Underflow" << endl;
        }else{
            int deq= arr[front];
            front = (front + 1) % cap;
            size--;
            return deq;
        }

    }

    bool isFull(){
        return size == cap;
    }

    bool isEmpty(){
        return size == 0;
    }

    int getFront(){
        return arr[front];
    }

    int getrear(){
        int rear = (front + size - 1) % cap;
        return rear;
    }


};