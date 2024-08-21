#include <bits/stdc++.h>
using namespace std;

// function to swapping two elements
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int partition(int arr[], int l, int h)
{
	int x = arr[h];
	int i = (l - 1);

	for (int j = l; j <= h - 1; j++) {
		if (arr[j] <= x) {
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[h]);
	return (i + 1);
}
void quickSortIterative(int arr[], int s, int l)
{
	// Create stack
	int stack[l - s + 1];

	// initialize top of stack
	int top = -1;

	// push initial values of s and l to stack
	stack[++top] = s;
	stack[++top] = l;

	while (top >= 0) {
		l = stack[top--];
		s = stack[top--];
		int p = partition(arr, s, l);
		if (p - 1 > s) {
			stack[++top] = s;
			stack[++top] = p - 1;
		}
		if (p + 1 < l) {
			stack[++top] = p + 1;
			stack[++top] = l;
		}
	}
}
int main(){
    cout << "Enter size of the array : ";
	int size; // size of the array
    cin>>size;
    clock_t start,end;

    int arr[size];
    for(int index=0;index<size;index++){
        arr[index]=rand()%10000;
    }
    start=clock();
    quickSortIterative(arr ,0 ,size);
    end =clock();
    
    double time =(double)(end-start)/CLOCKS_PER_SEC;
    cout<< time;
}