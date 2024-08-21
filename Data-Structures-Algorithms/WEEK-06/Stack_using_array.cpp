#include <iostream>
#include <ctime>

using namespace std;

int top = -1;

void Push(int S[], int n, int element) {
    top = top + 1;
    if (top >= n) {
        cout << "Stack overflow" << endl;
    }
    else {
        S[top] = element;
    }
}

void Pop(int S[]) {
    if (top == -1) {
        cout << "Stack underflow" << endl;
    }
    else {
        S[top] = -1;
        top = top - 1;
    }
}

bool isEmpty(){
    return top==-1;
}

bool isFull(int n){
    return top==n;
}

void StackTop(int S[]){
    if(isEmpty()){
        cout<<"Stack is empty";
    }
    else{
        cout<< S[top];
    }
}

void Display(int S[]) {
    if (top == -1) {
        cout << "Stack is empty" << endl;
    }
    else {
        cout << "Elements:" << endl;
        for (int i = top; i >= 0; i--) {
            cout << S[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int *S = new int[n]; 
    clock_t start, end;
    start = clock();
    for(int i=0; i<10; i++) {
        Push(S,n,rand()%100);
    }
    Display(S);
    for(int i=0;i<5;i++){
        Pop(S);
    }
    Display(S);
    for(int i=0; i<4; i++) {
        Push(S,n,rand()%100);
    }
    Display(S);
    end =clock();
    
    cout<< "Time :" << double(end-start)/CLOCKS_PER_SEC;

    return 0;
}