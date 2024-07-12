#include <iostream>
#include <string>

using namespace std;

class Heap {
private:
    int* arr;
    int capacity;
    int size;

public:
    Heap(int capacity) {
        this->capacity = capacity;
        this->size = 0;
        this->arr = new int[capacity];
    }

    ~Heap() {
        delete[] arr;
    }

    int Parent(int i) {
        return (i - 1) / 2;
    }

    int Left(int i) {
        return 2 * i + 1;
    }

    int Right(int i) {
        return 2 * i + 2;
    }

    void MaxHeapify(int i) {
        int left = Left(i);
        int right = Right(i);
        int largest = i;

        if (left < size && arr[left] > arr[largest]) {
            largest = left;
        }
        if (right < size && arr[right] > arr[largest]) {
            largest = right;
        }
        if (largest != i) {
            swap(arr[i], arr[largest]);
            MaxHeapify(largest);
        }
    }

    void BuildMaxHeap() {
        size = capacity; // Assuming array is already filled with elements
        for (int i = size / 2 - 1; i >= 0; i--) {
            MaxHeapify(i);
        }
    }

    void HeapSort() {
        BuildMaxHeap();
        int original_size = size;
        for (int i = size - 1; i >= 0; i--) {
            swap(arr[0], arr[i]);
            size--;
            MaxHeapify(0);
        }
        size = original_size; // Restore original size after sorting
    }

    int getMaximum() {
        return arr[0];
    }

    int extractMax() {
        if (size == 0) {
            return -1;
        }
        if (size == 1) {
            size--;
            return arr[0];
        }
        int root = arr[0];
        arr[0] = arr[size - 1];
        size--;
        MaxHeapify(0);
        return root;
    }

    void insert(int key) {
        if (size == capacity) {
            cout << "Error: Heap is full" << endl;
            return;
        }
        size++;
        int i = size - 1;
        arr[i] = key;
        while (i != 0 && arr[Parent(i)] < arr[i]) {
            swap(arr[i], arr[Parent(i)]);
            i = Parent(i);
        }
    }
};

int main() {
    Heap heap(10);
    heap.insert(3);
    heap.insert(2);
    heap.insert(15);
    heap.insert(5);
    heap.insert(4);
    heap.insert(45);

    cout << "Max: " << heap.getMaximum() << endl;
    cout << "Extracted Max: " << heap.extractMax() << endl;
    cout << "Max after extraction: " << heap.getMaximum() << endl;

    heap.HeapSort();
    for (int i = 0; i < 6; i++) {
        cout << heap.extractMax() << " ";
    }
    cout << endl;

    return 0;
}

