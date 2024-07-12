#include <iostream>

using namespace std;

class ArrayList{
private:
  int *arr;
  int capacity;
  int size;

  void resize(){
    int* newArr = new int[capacity*2];
    for(int i = 0; i < size; ++i){
      newArr[i] = arr[i];
    }
    delete[] arr; // Delocate memory
    arr = newArr;
    capacity *= 2;
  }

public:
  ArrayList(){
    capacity = 4;
    size = 0;
    arr = new int[capacity];
  }

  ~ArrayList(){
    delete[] arr;
  }
  
  void add(int data){
    if(size == capacity){
      resize();
    }
    arr[size] = data;
    size++;
  }

  int get(int idx){
    if(idx < 0 || idx >= size){
      cout << "Index out of bounds" << endl;
      return -1;
    }
    return arr[idx];
  }

  int getSize(){
    return size;
  }

  void pop(){
    if(size == 0){
      cout << "Empty array list" << endl;
      return;
    }
    size--;
  }

};

int main(){
  
  ArrayList list;

  list.add(10);
  list.add(20);
  list.add(30);
  list.add(40);

  cout << "Elements of array list: " << endl;
  for(int i = 0; i < list.getSize(); i++){
    cout << list.get(i) << endl;
  }

  list.pop();
  cout << "Elements of new poped list: " << endl;
  for(int i = 0; i < list.getSize(); i++){
    cout << list.get(i) << endl;
  }

  

  return 0;
}
