#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;


void QuickSort(vector<int>& arr, int left, int right) {
    int x = left, y = right;
    int pivot = arr[(left + right) / 2];

    while (x <= y) {
        while (arr[x] < pivot)
            x++;

        while (arr[y] > pivot)
            y--;

        if (x <= y) {
            swap(arr[x], arr[y]);
            x++;
            y--;
        }
    }

    if (left < y)
        QuickSort(arr, left, y);

    if (x < right)
        QuickSort(arr, x, right);
}
int main() {
    srand(time(nullptr)); // Initialize random seed

    int n;
    cout << "Enter size of the array: ";
    cin >> n;

    vector<int> arr(n);

    // Generate random array
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100; // random number between 0 and 99
    }

    auto start = high_resolution_clock::now(); // Start timer
    QuickSort(arr, 0, n-1);
    auto end = high_resolution_clock::now(); // End timer


    auto duration = duration_cast<microseconds>(end - start);
    cout << "Time taken by sorting function: " << duration.count() << " microseconds" << endl;

    return 0;
}