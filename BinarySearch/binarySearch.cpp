#include <iostream>
#include <string>
#include <cmath>  // Include cmath for standard mathematical functions

using namespace std;

bool binarySearch(int arr[], int high, int low, int x) {
    do {
        int mid = low + (high - low) / 2;  
        int v = arr[mid];
        if (v == x) {
            return true;
        } else if (v > x) {  // Correct comparison to x
            high = mid;  // Adjust to mid - 1
        } else {
            low = mid + 1;
        }
    } while (low < high);  // Correct condition to allow boundary checks
    return false;
}

int main() {
    int arr[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int x = 3;
    
    // Correct array index bounds
    bool result = binarySearch(arr, 8, 0, x);

    if (result) {
        cout << "Element is present in the array." << endl;
    } else {
        cout << "Element is not present in the array." << endl;
    }

    return 0;
}

