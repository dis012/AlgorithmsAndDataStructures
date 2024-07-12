#include <iostream>

using namespace std;

class Node{
public:
  int data; // Holds data for each node in the queue
  Node* next; // Pointer to the next node in the queue

  Node(int data){ // Constructor that initalizes a new node 
    this->data = data; // Set the node's data 
    this->next = nullptr; // Set the node's next pointer to null 
  }
};

class Queue{
private:
  Node* front; // Pointer to the front of the queue
  Node* rear; // Pointer to the back of the queue

public:
  Queue(){ // Constructor that initializes the queue
    front = nullptr; // Set the front pointer to null
    rear = nullptr; // Set the rear pointer to null
  }

  void enqueue(int data){
    Node* newNode = new Node(data);
    if(rear==nullptr){
      front = rear = newNode;
      return;
    }
    rear->next = newNode;
    rear = newNode;
  }

  void dequeue(){
    if(front ==nullptr){
      cout << "Queue is empty" << endl;
      return;
    }
    Node* temp = front;
    front = front->next;

    if(front == nullptr){
      rear = nullptr;
    }

    delete temp;
  }

  bool isEmpty(){
    return front == nullptr;
  }

  int getfront(){
    if(front == nullptr){
      cout << "Queue is empty" << endl;
      return -1;
    }
    return front->data;
  }
};



int main(){
  Queue q;
  q.enqueue(10);
  q.enqueue(20);
  q.enqueue(30);

  cout << "The front element is: " << q.getfront() << "\n";
  q.dequeue();
  cout << "The front element is: " << q.getfront() << "\n";

  if(!q.isEmpty()){
    cout << "Queue is not empty" << endl;


  return 0;
  }
}

