//4. Count Nodes
//Write a function to count the number of nodes in a singly linked list using only one
//pointer.



int countNodes(Node *head) {
    int count = 0;
    Node *current = head;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}



//10.Remove Duplicates
//A linked list contains duplicate values. Design an algorithm to remove duplicates
//without using any extra arrays or lists.
//Explain the logical steps clearly

void removeDuplicates(Node* head) {
    Node* current = head;
    while (current) {
        Node* runner = current;
        while (runner->next) {
            if (runner->next->Data == current->Data) {
                Node* temp = runner->next;
                runner->next = runner->next->next;
                delete temp;
            } else {
                runner = runner->next;
            }
        }
        current = current->next;
    }
}






//choose questions

//1..... answer is A

//2..... answer is A