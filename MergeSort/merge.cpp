#include <iostream>

using namespace std;

void merge(int *arr, int l, int m, int h){
  int a1 = m - l + 1;
  int a2 = h - m;

  int *arr1 = new int[a1];
  int *arr2 = new int[a2];

  for(int i = 0; i < a1; i++){
    arr1[i] = arr[l + i];
  }

  for(int j = 0; j < a2; j++){
    arr2[j] = arr[m + 1 + j];
  }

  int i = 0, j = 0, k = l;
  while(i < a1 && j < a2){
    if(arr1[i] <= arr2[j]){
      arr[k] = arr1[i];
      i++;
    }
    else{
      arr[k] = arr2[j];
      j++;
    }
    k++;
  }

  while(i < a1){
    arr[k] = arr1[i];
    i++;
    k++;
  }

  while(j < a2){
    arr[k] = arr2[j];
    j++;
    k++;
  }
}

void mergeSort(int *arr, int l, int h){
  if(l < h){
    int m = (h + l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, h);
    merge(arr, l, m, h);
  }
}

void printArray(int *arr, int n){
  for(int i = 0; i < n; i++){
    cout << arr[i] << " ";
  }
  cout << endl;
}

int main(){

  int arr[] = {4,7,25,3,6,8,1,2,5,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24};
  int n = sizeof(arr) / sizeof(arr[0]);

  mergeSort(arr, 0, n - 1);

  cout << "Sorted array: ";
  printArray(arr, n);

  return 0;
}
