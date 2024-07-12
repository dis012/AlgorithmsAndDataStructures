#include <iostream>

using namespace std;

class ArrayBuffer{
private:
  int* arr;
  int capacity;
  int head;
  int tail;

  void resize(){
    int* newArr = new int[capacity*2];
    int newSize = tail - head;

    for(int i = 0; i < newSize; i++){
      newArr[i] = arr[i];
    }
    delete[] arr;
    arr = newArr;
    capacity *= 2;
    head = 0;
    tail = newSize;
  }

public:
  ArrayBuffer(){
    capacity = 4;
    arr = new int[capacity];
    head = 0;
    tail = 0;
  }

  ~ArrayBuffer(){
    delete[] arr;
  }

  void addTail(int data){
    if(tail == capacity){
      resize();
    }
    arr[tail] = data;
    tail++;
  }

  void addHead(int data){
    if(head == 0){
      resize();
    }
    arr[head] = data;
    head--;
  }

  int removeTail(){
    if(tail == head){
      cout << "Buffer empty" << endl;
      return -1;
    }
    return arr[--tail];
  }

  int removeHead(){
    if(head == tail){
      cout << "Buffer empty" << endl;
      return -1;
    }
    return arr[++head];
  }

};

int main(){
  
  ArrayBuffer buffer;

  buffer.addTail(10);
  buffer.addTail(20);
  buffer.addTail(30);

  buffer.addHead(5);
  buffer.addHead(6);
  buffer.addHead(7);

  cout << "Removed from tail: " << buffer.removeTail() << endl;
  cout << "Removed from tail: " << buffer.removeTail() << endl;

  cout << "Removed from head: " << buffer.removeHead() << endl;
  cout << "Removed from head: " << buffer.removeHead() << endl;


  return 0;
}
