<<<<<<< HEAD
// We need you to construct the code of the Stack Calculator that we previously explained in the Stack sessions.
// You should implement the calculator using a stack data structure in C++ (array or linked list implementation as discussed in class).
// Required Functions
// bool isEmpty()
// Returns true if the stack is empty.
// bool isFull()
// Returns true if the stack is full (for array implementation).
// void push(int value)
// Pushes a value onto the stack (with overflow check).
// int pop()
// Removes and returns the top element (with underflow check).
// int peek()
// Returns the top element without removing it.
// string infixToPostfix(string expression)
// Converts a valid infix arithmetic expression (e.g., 3+5*2) into a postfix expression (e.g., 3 5 2 * +) using a stack.
// Follow operator precedence: * and / have higher precedence than + and -.
// Handle parentheses ( and ).
// Assume operands are single-digit integers, as explained in the session.
// The output should be a space-separated postfix expression.
// int evaluatePostfix(string expression)
// Evaluates a postfix expression using the stack and returns the final result.
// Supports: + , - , * , /
// Assume operands are single-digit integers.
//  Program Requirements
// Your main program should:
// Ask the user to enter an infix expression.
// Convert it to postfix using infixToPostfix().
// Evaluate the resulting postfix expression using evaluatePostfix().
// Print both:
// The postfix expression
// The final result
// Handle invalid expressions (not enough operands, extra operators, mismatched parentheses, division by zero, etc.) with clear error messages.
// Please make sure your code is clean, well-commented, and organized.


#include <iostream>
#include <string>
#include <cctype>
#include <sstream>
using namespace std;
const int MAX_SIZE = 100;
class Stack {
private:
    int arr[MAX_SIZE];
    int top;
public:
    Stack() : top(-1) {}
    bool isEmpty() {
        return top == -1;
    }
    bool isFull() {
        return top == MAX_SIZE - 1;
    }
    void push(int value) {
        if (isFull()) {
            throw runtime_error("Stack Overflow");
        }
        arr[++top] = value;
    }
    int pop() {
        if (isEmpty()) {
            throw runtime_error("Stack Underflow");
        }
        return arr[top--];
    }
    int peek() {
        if (isEmpty()) {
            throw runtime_error("Stack is empty");
        }
        return arr[top];
    }
};
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

string infixToPostfix(string expression) {
    Stack stack;
    string postfix;
    for (char ch : expression) {
        if (isdigit(ch)) {
            postfix += ch;
            postfix += ' ';
        } else if (ch == '(') {
            stack.push(ch);
        } else if (ch == ')') {
            while (!stack.isEmpty() && stack.peek() != '(') {
                postfix += (char)stack.pop();
                postfix += ' ';
            }
            if (!stack.isEmpty() && stack.peek() == '(') {
                stack.pop();
            } else {
                throw runtime_error("Mismatched parentheses");
            }
        } else { 
            while (!stack.isEmpty() && precedence(stack.peek()) >= precedence(ch)) {
                postfix += (char)stack.pop();
                postfix += ' ';
            }
            stack.push(ch);
        }
    }
    while (!stack.isEmpty()) {
        if (stack.peek() == '(') {
            throw runtime_error("Mismatched parentheses");
        }
        postfix += (char)stack.pop();
        postfix += ' ';
    }
    return postfix;
}
int evaluatePostfix(string expression) {
    Stack stack;
    istringstream iss(expression);
    string token;
    while (iss >> token) {
        if (isdigit(token[0])) {
            stack.push(stoi(token));
        } else {
            int val2 = stack.pop();
            int val1 = stack.pop();
            int result;
            switch (token[0]) {
                case '+': result = val1 + val2; break;
                case '-': result = val1 - val2; break;
                case '*': result = val1 * val2; break;
                case '/':
                    if (val2 == 0) throw runtime_error("Division by zero");
                    result = val1 / val2; break;
                default:
                    throw runtime_error("Invalid operator");
            }
            stack.push(result);
        }
    }
    return stack.pop();
}
int main() {
    string infixExpression;
    cout << "Enter an infix expression: ";
    getline(cin, infixExpression);
    try {
        string postfixExpression = infixToPostfix(infixExpression);
        cout << "Postfix Expression: " << postfixExpression << endl;
        int result = evaluatePostfix(postfixExpression);
        cout << "Final Result: " << result << endl;
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
    return 0;
}
=======
// We need you to construct the code of the Stack Calculator that we previously explained in the Stack sessions.
// You should implement the calculator using a stack data structure in C++ (array or linked list implementation as discussed in class).
// Required Functions
// bool isEmpty()
// Returns true if the stack is empty.
// bool isFull()
// Returns true if the stack is full (for array implementation).
// void push(int value)
// Pushes a value onto the stack (with overflow check).
// int pop()
// Removes and returns the top element (with underflow check).
// int peek()
// Returns the top element without removing it.
// string infixToPostfix(string expression)
// Converts a valid infix arithmetic expression (e.g., 3+5*2) into a postfix expression (e.g., 3 5 2 * +) using a stack.
// Follow operator precedence: * and / have higher precedence than + and -.
// Handle parentheses ( and ).
// Assume operands are single-digit integers, as explained in the session.
// The output should be a space-separated postfix expression.
// int evaluatePostfix(string expression)
// Evaluates a postfix expression using the stack and returns the final result.
// Supports: + , - , * , /
// Assume operands are single-digit integers.
//  Program Requirements
// Your main program should:
// Ask the user to enter an infix expression.
// Convert it to postfix using infixToPostfix().
// Evaluate the resulting postfix expression using evaluatePostfix().
// Print both:
// The postfix expression
// The final result
// Handle invalid expressions (not enough operands, extra operators, mismatched parentheses, division by zero, etc.) with clear error messages.
// Please make sure your code is clean, well-commented, and organized.


#include <iostream>
#include <string>
#include <cctype>
#include <sstream>
using namespace std;
const int MAX_SIZE = 100;
class Stack {
private:
    int arr[MAX_SIZE];
    int top;
public:
    Stack() : top(-1) {}
    bool isEmpty() {
        return top == -1;
    }
    bool isFull() {
        return top == MAX_SIZE - 1;
    }
    void push(int value) {
        if (isFull()) {
            throw runtime_error("Stack Overflow");
        }
        arr[++top] = value;
    }
    int pop() {
        if (isEmpty()) {
            throw runtime_error("Stack Underflow");
        }
        return arr[top--];
    }
    int peek() {
        if (isEmpty()) {
            throw runtime_error("Stack is empty");
        }
        return arr[top];
    }
};
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

string infixToPostfix(string expression) {
    Stack stack;
    string postfix;
    for (char ch : expression) {
        if (isdigit(ch)) {
            postfix += ch;
            postfix += ' ';
        } else if (ch == '(') {
            stack.push(ch);
        } else if (ch == ')') {
            while (!stack.isEmpty() && stack.peek() != '(') {
                postfix += (char)stack.pop();
                postfix += ' ';
            }
            if (!stack.isEmpty() && stack.peek() == '(') {
                stack.pop();
            } else {
                throw runtime_error("Mismatched parentheses");
            }
        } else { 
            while (!stack.isEmpty() && precedence(stack.peek()) >= precedence(ch)) {
                postfix += (char)stack.pop();
                postfix += ' ';
            }
            stack.push(ch);
        }
    }
    while (!stack.isEmpty()) {
        if (stack.peek() == '(') {
            throw runtime_error("Mismatched parentheses");
        }
        postfix += (char)stack.pop();
        postfix += ' ';
    }
    return postfix;
}
int evaluatePostfix(string expression) {
    Stack stack;
    istringstream iss(expression);
    string token;
    while (iss >> token) {
        if (isdigit(token[0])) {
            stack.push(stoi(token));
        } else {
            int val2 = stack.pop();
            int val1 = stack.pop();
            int result;
            switch (token[0]) {
                case '+': result = val1 + val2; break;
                case '-': result = val1 - val2; break;
                case '*': result = val1 * val2; break;
                case '/':
                    if (val2 == 0) throw runtime_error("Division by zero");
                    result = val1 / val2; break;
                default:
                    throw runtime_error("Invalid operator");
            }
            stack.push(result);
        }
    }
    return stack.pop();
}
int main() {
    string infixExpression;
    cout << "Enter an infix expression: ";
    getline(cin, infixExpression);
    try {
        string postfixExpression = infixToPostfix(infixExpression);
        cout << "Postfix Expression: " << postfixExpression << endl;
        int result = evaluatePostfix(postfixExpression);
        cout << "Final Result: " << result << endl;
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
    return 0;
}
>>>>>>> d576c068600eadaecd8ecaa525361e1cbe86faaf
