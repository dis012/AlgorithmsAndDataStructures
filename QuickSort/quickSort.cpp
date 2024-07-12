#include <iostream>

using namespace std;

int partition(int arr[], int low, int high){
  int pivot = arr[high];

  int idx = low - 1;

  for(int i = low; i < high; i++){
    if(arr[i] <= pivot){
      idx++;
      int tmp = arr[i];
      arr[i] = arr[idx];
      arr[idx] = tmp;
    }
  }

  idx++;
  arr[high] = arr[idx];
  arr[idx] = pivot;

  return idx;

}


void QuickSort(int arr[], int low, int high){
  if(low >= high){
    return;
  }

  int pivotIdx = partition(arr, low, high);

  QuickSort(arr, low, pivotIdx - 1);
  QuickSort(arr, pivotIdx + 1, high);
}


int main(){
  
  int arr[] = {9,3,7,4,69,420,42};

  QuickSort(arr, 0, 6);

  for(int i = 0; i < 7; i++){
    cout << arr[i] << " ";
  }

  return 0;
}
