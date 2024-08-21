#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

// Inorder traversal
void traverseInOrder(struct node *root) {  
  if (root != NULL) {  //if the root is not null
    traverseInOrder(root->left);  //go to the left node of the root
    cout << root->key << " ";   //output the key value
    traverseInOrder(root->right);  //go to the right node of the root
  }
}

struct node* newNode(int key) {  //creating a new node if the tree is empty
  struct node* node = new struct node;
  node->key = key;  //add the value to the node
  node->left = NULL;
  node->right = NULL;
  return node;
}

// Insert a node
struct node *insertNode(struct node *node, int key) {
  if (node == NULL){  //creating a new node if no tree is present
      return newNode(key);
  }
  if (key < node->key){   //if key value is less than the root value
    node->left = insertNode(node->left, key);   //add the key to the left node of the root
  }
  else if (key > node->key){  //if key value is higher than root value
    node->right = insertNode(node->right, key); //add the key value to the right of the root
  }
  return node;
}

// finding the minimum 
struct node* findingNode(struct node* node) {
  struct node* a = node;
  while (a && a->left != NULL)
    a = a->left;
  return a;
}

// Deleting a node
struct node *deleteNode(struct node *root, int key) {
  if (root == NULL){
      return root;
  }    
  if (key > root->key){  //if the value to be deleted is higher than the root value
    root->right = deleteNode(root->right, key);  //search for the right subtree
  }
  else if (key < root->key){    //if the value to be deleted is less than the root value
    root->left = deleteNode(root->left, key);  //search for the left subtree
  }
  
  else {  //if the value to be deleted is the root value
    if (root->left == NULL) {  //if the root has only a right subtree
      struct node *x = root->right;
      free(root);
      return x;
    }
    else if (root->right == NULL) { //if the root has only a left subtree
      struct node *x = root->left;
      free(root);
      return x;
    }
    //if root has 2 children
    struct node* x = findingNode(root->right);
    root->key = x->key;
    root->right = deleteNode(root->right, x->key);
  }
  return root;
}

// Driver code
int main() {
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }
  traverseInOrder(root);
}
 

