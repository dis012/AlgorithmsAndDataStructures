#include <iostream>

using namespace std;

void CountingSort(int *A, int *B,int k, int a){
  int C[k];
  
  for(int i = 0; i < k; i++){
    C[i] = 0;
  }

  for(int j = 0; j < a; j++){
    C[A[j]] += 1;
  }

  for(int i = 1; i < k; i++){
    C[i] += C[i - 1];
  }

  for(int j = a-1; j >= 0; j--){
    B[C[A[j]] - 1] = A[j];
    C[A[j]] -= 1;
  }
}


int main(){
  
  int arr1[] = {2, 3, 1, 4, 2, 3, 1, 3};
  int len = sizeof(arr1) / sizeof(arr1[0]);
  int arr2[len];

  CountingSort(arr1, arr2, 5, len);

  for(int i = 0; i < len; i++){
    cout << arr2[i] << " ";
  }

  return 0;
}
