#include <iostream>
#include <string>

using namespace std;

int search(int arr[], int n, int x){
  for(int i = 0; i < n; i++){
    if(arr[i] == x){
      return i;
    }
  }
  return -1;
}


int main(){
  
  int arr[6] = {1, 2, 3, 4, 5, 6};
  int x = 3;
  int n = sizeof(arr)/sizeof(arr[0]);

  int result = search(arr, n, x);
  if (result == -1){
    cout << "Element is not present in the array." << endl;
  } else {
    cout << "Element is present at index " << result << endl;
  }

  return 0;
}
