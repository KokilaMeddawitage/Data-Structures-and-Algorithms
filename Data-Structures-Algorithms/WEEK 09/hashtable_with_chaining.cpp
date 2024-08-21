#include <iostream>
#include "linkedlist.cpp"
using namespace std;

struct HashTable{
    int MAX_LENGTH = 4;
    int MAX_CHAIN_LENGTH = 2;
    LinkedList * password = new LinkedList[MAX_LENGTH];
    bool isFull(){
        bool full = true;
        int count = 0;
        for (int i = 0; i < MAX_LENGTH; i++){
            if(password[i].head == NULL){
                full = false;
            }
        }
        return full;
    }
    int hashfunc(string user_name){
        int sum = 0;
        int hash = 0;
        for(int i = 0;i< user_name.length(); i++){
            sum += int(user_name[i]);

        }
        hash = sum % MAX_LENGTH;

        return hash;
    }
    bool is_slot_empty(int hash){
        bool empty;
        if(password[hash].head==NULL){
            empty = true;
        }
        else{
            empty=false;
        }
        return empty;
    }
    void insert(string user_name,string user_password){
        int hash;
        bool empty;
        hash = hashfunc(user_name);
        empty = is_slot_empty(hash);
        if(password[hash].length<MAX_CHAIN_LENGTH){
            password[hash].insert(user_name.data(),user_password.data());

        }
        else{
            cout<<"Linked List reached MAX CAP!\n";
        }
    }
    void print_hashtable(){
        for(int i=0;i<MAX_LENGTH;i++){
            cout<<"["<<i<<"]-->";
            password[i].print_list();
        }
    }
    void hash_lookup(string user_name){
        int hash;
        bool empty;
        hash = hashfunc(user_name);
        empty = is_slot_empty(hash);
	//add your code below
	if (empty){ //if the relavent slot of the hash table is empty
	        cout << "No password matches with the username" << endl;
	    }else{  //if the relavant slot is not empty
	        Node *point = password[hash].head;  //point the "point" pointer variable to the head of the linked list
	        
	        //iterate through the linked list when the collissions occur 
	        while(point!=NULL && point->user_name!=user_name){  
	            point=point->link;  //point the "point" pointer variable to the next pposition
	        }
	        if (point==NULL){   //if the pointed value of the linked list is null
	            cout << "No password matches for the given username "<< endl;
	        }else{  //if the username matches,
	            cout << "Password for the given "<< user_name<<" is "<<point->password<<endl;
	        }
	    }
    }
};

int main(){
    HashTable * hashtbl = new HashTable;
    cout<< hashtbl->isFull()<<"\n";
    int command=0;
    string user_name;
    string password;
    while (command!=-1){
        /* code */
        cout << "Type command: ";
        cin >> command;
        switch (command){
        case 1:
            /* insert the new item*/
            cout << "Enter user name: ";
            cin >> user_name;
            cout << "Enter password to be saved: ";
            cin >> password;
            hashtbl->insert(user_name,password);
            break;
        case 2:
            /* hash lookup password*/
            cout << "Enter user name to look up password:";
            cin >> user_name;
            hashtbl->hash_lookup(user_name);
            break;
        case 3:
            hashtbl->print_hashtable();
            break;
        case -1:
            /* hash lookup password*/
            hashtbl->print_hashtable();
            cout << "Exiting...\n";
            break;
        
        }
    
    }
    return 0;
}
