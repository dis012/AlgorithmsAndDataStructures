#include <iostream>
#include <string>

void insertSort(int arr[], int size) {
    for (int j = 1; j < size; j++) {
        int key = arr[j];
        int i = j - 1;
        while (i >= 0 && arr[i] > key) {
            arr[i + 1] = arr[i];
            i--;
        }
        arr[i + 1] = key;
    }
}

void insertSort2(int arr[], int size){
    for(int j = 1; j < size; j++){
        int key = arr[j];
        int i = j - 1;
        while(i >= 0 && arr[i] < key){
            arr[i+1] = arr[i];
            i--;
        }
        arr[i+1]  = key;
    }
}

int main() {
    int arr[] = {5, 2, 4, 6, 1, 3};
    int size = sizeof(arr) / sizeof(arr[0]);

    insertSort(arr, size);

    std::cout << "Sorted Array: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    insertSort2(arr, size);

    std::cout << "Sorted Array backwards: ";
    for(int i = 0; i < size; i ++){
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;

    return 0;
}
