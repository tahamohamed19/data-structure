class Stack{
    int top;
    int size;
    int *arr;

    public:
    
    Stack(int s){
        size = s;
        arr = new int[size];
        top = -1;
    }

    void push(int x){
        if ( top == (size-1)){
            cout << "Stack Overflow" << endl;
        }
        else{
            arr[++top] = x;
        }
    }

    int pop(){
        if(top == -1){
            cout << "Stack Underflow" << endl;
            return -1;
        }else{
            return arr[top--];
        }
    }


    int topval(){
        if(top == -1){
            cout << "Stack is empty"<<endl;
            return -1;
        }else{
            return arr[top];
        }
    }

    bool isEmpty(){
        return top == -1;
    }

    bool isFull(){
        return top == (size-1);
}
};