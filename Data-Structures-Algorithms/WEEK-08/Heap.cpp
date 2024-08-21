#include <iostream>
using namespace std;
  
// function to heapify the tree
void heapify(int arr[], int n, int root){
   // build heapify
   int max=root;   //assign the value of the root to max
   int l=2*root+1;  //left index of the root
   int r=2*root+2;    //right index of the root
   if (l<n && arr[l] > arr[max]){   //if the left child is larger than the root node
       max=l;   //assign the index of the left child to max
   }
   if (r < n && arr[r] > arr[max]){  //if the right child is larger than the root node
       max=r;   //assign the index of the right child to max
   }
   if (max!=root){   //if child of roots are larger
       swap(arr[root],arr[max]);   //swap the larger value and the root value
       heapify(arr,n,max);  //call the heapify function recursively
   }
}
  
// implementing heap sort
void heapSort(int arr[], int n){
   // build heap
   for (int x=n/2-1; x>=0; x--){    //heapify the given array of elements
       heapify(arr,n,x);
   }
   // extracting elements from heap one by one
   for (int x= n-1; x>=0; x--){
       swap(arr[0],arr[x]);    //swap the root element with the last element
       heapify(arr,x,0);   //after swapping, heapify the function again
   }
}
  
/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}
  
// main program
int main(){
   int n;
   cout << "Enter the size of the array: "<<endl;  //get the size of the array from the user
   cin >> n;
   cout<<"Enter the values: "<<endl;
   int heap_arr[n];
   for (int i=0;i<n;i++){   //get the inputs from the user
       cin >> heap_arr[i];
   }
   cout<<"Input array"<<endl;
   displayArray(heap_arr,n);
  
   heapSort(heap_arr, n);
  
   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n);
}