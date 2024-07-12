#include <iostream>

using namespace std;

class Node{
public:
  Node* prev;
  Node* next;
  int data;

  Node(int data){
    this->data = data;
    this->prev = nullptr;
    this->next = nullptr;
  }
};

class LinkedList{
private:
  Node* head;
  Node* tail;

public:
  LinkedList(){
    head = nullptr;
    tail = nullptr;
  }

  void insertBeginig(int data){
    Node* newNode = new Node(data);
    if(head == nullptr){
      head = tail = newNode;
      return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
  }

  void insertEnd(int data){
    Node* newNode = new Node(data);
    if(tail == nullptr){
      head = tail = newNode;
      return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
  }

  void removeBegining(){
    if(head == nullptr){
      cout << "Error: Empty list" << endl;
      return;
    }
    Node* temp = head;
    head = head->next;
    if(head) {
       head->prev = nullptr;
    }
    delete temp;
  }

  void removeEnd(){
    if(tail == nullptr){
      cout << "Error: Empty list" << endl;
      return;
    }
    Node* temp = tail;
    tail = tail->prev;
    if(tail) {
      tail->next = nullptr;
    }
    delete temp;
  }
  
  int displayForward(){
    if(head == nullptr){
      cout << "Error: Empty list" << endl;
      return -1;
    }
    return head->data;
  }

  int displayEnd(){
    if(tail == nullptr){
      cout << "Error: Empty list" << endl;
      return -1;
    }
    return tail->data;
  }

  void addNode(int data, int pos){
    Node* newNode = new Node(data);
    Node* current = head;
    if(pos == 0){
      insertBeginig(data);
      return;
    }
    for(int i = 1; i < pos-1; i++){
      if(current == nullptr){
        cout << "Error: Index out of bounds" << endl;
        return;
      }
      current = current->next;
    }

    if(current==tail){
      insertEnd(data);
      return;
    }
    newNode->next = current->next;
    current->next->prev = newNode;
    current->next = newNode;
    newNode->prev = current;
  }

  void removeNode(int pos){
    if(head==nullptr){
      cout << "Error: Empty list" << endl;
      return;
    }

    if(pos == 0){
      removeBegining();
      return;
    }

    Node* current = head;
    for(int i = 1; i < pos; i++){
      if(current->next == nullptr){
        cout << "Error: Index out of bounds" << endl;
        return;
      }
      current = current->next;
    }

    if(current == tail){
      removeEnd();
      return;
    }
    
    Node* prevNode = current->prev;
    Node* nextNode = current->next;

    prevNode->next = nextNode;
    nextNode->prev = prevNode;
    delete current;
  }

  void displayList(){
    Node* current = head;
    while(current){
      cout << current->data << endl;
      current = current->next;
    }
  }


};


int main(){
  
  LinkedList list;
  cout << "Inserting at the begining" << endl;
  list.insertBeginig(1);
  list.insertBeginig(2);
  list.insertBeginig(3);
  list.insertBeginig(4);
  list.insertBeginig(5);
  list.displayList();
  cout << "Inserting at the end" << endl;
  list.insertEnd(6);
  list.insertEnd(7);
  list.insertEnd(8);
  list.insertEnd(9);
  list.insertEnd(10);
  list.displayList();
  cout << "Removing from the begining" << endl;
  list.removeBegining();
  list.removeBegining();
  list.displayList();
  cout << "Removing from the end" << endl;
  list.removeEnd();
  list.removeEnd();
  list.displayList();
  cout << "Adding nodes 2(11), 5(12) and 7(13)" << endl;
  list.addNode(11, 2);
  list.addNode(12, 5);
  list.addNode(13, 7);
  list.displayList();
  cout << "Removing added nodes" << endl;
  list.removeNode(2);
  list.removeNode(4);
  list.removeNode(5);
  list.displayList();
  

  return 0;
}
