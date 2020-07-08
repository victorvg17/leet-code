
#include <iostream>
using namespace std;

struct Node{
  int data;
  struct Node* next;
};

class MyLinkedList {
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
      head = nullptr;
      tail = nullptr;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index);

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val);

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val);

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val);

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index);
private:
    Node* head;
};

int MyLinkedList::get(int index){

}

void MyLinkedList::addAtHead(int val) {
  Node* tmp = new Node();
  tmp->data = val;
  tmp->next = head;

  head = tmp;
}

void MyLinkedList::addAtTail(int val) {
  Node* tmp = new Node();
  tmp->data = val;
  tmp->next = nullptr;

  Node* last = head;
  if (head == nullptr) {
    head = tmp;
    return;
  }

  while (last->next != nullptr) {
    last = last->next;
  }
  last->next = tmp;
}

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
