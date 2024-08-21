#include <iostream>
#include <ctime>

using namespace std;
//create the linked list
struct Node { 
   int data;
   struct Node *next;
};
struct Node* top = NULL;
//insert values
void Push(int element) {
    Node* newNode = new Node();
    newNode->data = element;
    newNode->next = top;
    top = newNode;
}
//removing values
void Pop() { 
    if (top == NULL) {
        cout << "Stack underflow" << endl;
    }
    else {
        Node* temp = top;
        top = top->next;
        delete temp;
    }
}
//empty or not
bool isEmpty() { 
    return top == NULL;
}
//display elements
void StackTop() { 
    if (isEmpty()) {
        cout << "Stack is empty" << endl;
    }
    else {
        cout << top->data << endl;
    }
}
 // display the stack
void display() { // displaying the stack
    if (top == NULL) {
        cout << "Stack is empty" << endl;
    }
    else {
        cout << "Elements: ";
        Node* temp = top;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}


int main() {
    struct S;
    clock_t start, end;

    // Measuring time taken
    start = clock();
    for(int i=0; i<10; i++) {
        Push(rand()%100);
    }
    display();
    for(int z=0;z<5;z++){
        Pop();
    }
    
    display();
    for(int i=0; i<4; i++) {
        Push(rand()%100);
    }
    display();
    end =clock();
    
    cout<< "Time :"<< double(end-start)/CLOCKS_PER_SEC;
    end = clock();
    
    return 0;
}