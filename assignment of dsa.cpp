#include <iostream>
using namespace std;
class Node{
public:
    int data;
    Node *left, *right;
    Node(int val){
        data = val;
        left = right = NULL;
    }
};
class BST{
    public:
    Node *root;
    BST(){
        root = NULL;
    }
    Node* insert(Node *r, int item){
        if (root == NULL){
            Node *newNode = new Node(item);
            r = newNode;
        }else if(item < r->data){
            r->left = insert(r->left, item);
        }else{
            r->right = insert(r->right, item);
        }
        return r;
    }
    void preOrder(Node *r){
        if(r == NULL) return;
        cout << r->data << "/t";
        preOrder(r->left);
        preOrder(r->right);
    }
    void preOrder(){
        preOrder(root);
    }
    void inOrder(Node *r){
        inOrder(r->left);
        cout << r->data << "/t";
        inOrder(r->right);
    }
    void postOrder(Node *r){
        postOrder(r->left);
        postOrder(r->right);
        cout << r->data << "/t";
    }
    Node* search(Node* r, int key){
        if(r == NULL){
            return NULL;
        }else if(r->data == key){
            return r;
        }else if(key < r->data){
            return search(r->left, key);
        }else{
            return search(r->right, key);
        }
    }
    Node* search(int key){
        search(root, key);
    }
    Node* findMin(Node* r){
        if(r == NULL){
            return NULL;
        }else if (r->left == NULL){
            return r;
        }else{
            return findMin(r->left);
        }
    }
    Node* findMax(Node* r){
        if(r == NULL){
            return NULL;
        }else if (r->right == NULL){
            return r;
        }else{
            return findMin(r->right);
        }
    }
};
