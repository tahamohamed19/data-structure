#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
using namespace std;

class Stack {
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
            cout << "Stack is empty" << endl;
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

    int peek(){
        if(top == -1){
            cout << "Stack is empty" << endl;
            return -1;
        }else{
            return arr[top];
        }
    }
    
};


int precedence(char op){
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

string infixToPostfix(string exp){
    Stack opStack(100);
    string postfix = "";

    for (int i = 0; i < exp.length(); i++){
        char ch = exp[i];

        if (isspace(ch)) continue;

        if (isdigit(ch)){
            postfix += ch;
            postfix += ' ';
        }

        else if (ch == '('){
            opStack.push(ch);
        }


        else if (ch == ')'){
            while (!opStack.isEmpty() && opStack.topval() != '('){
                postfix += (char)opStack.pop();
                postfix += ' ';
            }

 
            if (opStack.isEmpty()){
                cout << "Error: mismatched parentheses\n";
                return "Invalid expression";
            }

            opStack.pop(); 
        }


        else if (ch=='+' || ch=='-' || ch=='*' || ch=='/'){
            while (!opStack.isEmpty() &&
                   precedence(opStack.topval()) >= precedence(ch)){
                if (opStack.topval() == '('){
                    cout << "Error: mismatched parentheses\n";
                    return "Invalid expression";
                }
                postfix += (char)opStack.pop();
                postfix += ' ';
            }
            opStack.push(ch);
        }


        else {
            cout << "Invalid character: " << ch << endl;
            return "Invalid expression";
        }
    }

    while (!opStack.isEmpty()){
        if (opStack.topval() == '('){
            cout << "Error: mismatched parentheses\n";
            return "Invalid expression";
        }
        postfix += (char)opStack.pop();
        postfix += ' ';
    }

    return postfix;
}


int evaluatePostfix(string exp){
    Stack st(100);
    stringstream ss(exp);
    string token;

    while (ss >> token){
        if (isdigit(token[0])){
            st.push(token[0] - '0');
        }else {
            int b = st.pop();
            int a = st.pop();

            if (a == -1 || b == -1){
                cout << "Error: Not enough operands\n";
                return -1;
            }

            int result = 0;

            switch(token[0]){
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/':
                    if (b == 0){
                        cout << "Error: Division by zero\n";
                        return -1;
                    }
                    result = a / b; break;
            }

            st.push(result);
        }
    }

    return st.pop();
}

int main(){
    cout << "Enter infix expression: ";
    string infix;
    getline(cin, infix);

    string postfix = infixToPostfix(infix);
    cout << "Postfix: " << postfix << endl;

    int result = evaluatePostfix(postfix);
    cout << "Result: " << result << endl;

return 0;
}