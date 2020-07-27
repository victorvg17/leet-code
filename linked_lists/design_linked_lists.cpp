#include <iostream>

using namespace std;

struct Node {
  int x;
  Node* next;
};

class MyLinkedList {
  public:
    /** Initialize your data structure here. */
    MyLinkedList() {
      head = nullptr;
      length = 0;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
      Node* runner = head;
      int count = 0;

      while (runner != nullptr) {
        if (count == index){
          return runner->x;
        }
        count++;
        runner = runner->next;
      }

      //invalid case
      return -1;
    }

    /** Add a node of value val before the first element of the linked list.
      After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
      Node* newbie = new Node();
      newbie->x = val;
      newbie->next = head;
      head = newbie;
      length++;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
      Node* newbie = new Node();
      newbie->x = val;
      newbie->next = nullptr;
      Node* runner = head;
      while (runner->next != nullptr) {
        runner = runner->next;
      }
      runner->next = newbie;
      length++;
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list,
    the node will be appended to the end of linked list. If index is greater than the length,
    the node will not be inserted. */
    void addAtIndex(int index, int val) {
      if (index == 0) {
        addAtHead(val);
        return;
      }

      Node* newbie = new Node();
      newbie->x = val;

      int count = 0;
      Node* prev = new Node();
      Node* curr = head;
      while(count != index) {
        if (count == index-1) {
          prev = curr;
          length++;
        }
        count++;
        curr = curr->next;
      }

      prev->next = newbie;
      newbie->next = curr;
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
      if (index >= length || index < 0){
        return;
      }
      //special case when there is a hit on the head itself
      else if (index == 0) {
        head = head->next;
        length--;
        return;
      }
      int count = 0;
      Node* prev = new Node();
      Node* curr = head;

      while(count != index) {
        if (count == index-1){
          prev = curr;
          length--;
        }
        count++;
        curr = curr->next;
      }
      prev->next = curr->next;
    }

    void printLinkedList() {
      cout << "current linkedList: " << endl;
      for (Node* runner = head ; runner != nullptr;) {
        cout << runner->x << endl;
        runner = runner->next;
      }
    }

  private:
    Node* head;
    int length;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
int main() {
  MyLinkedList* linkedList = new MyLinkedList();
  int test_x;

  linkedList->addAtHead(1);
  linkedList->printLinkedList();
  linkedList->addAtTail(3);
  linkedList->printLinkedList();
  linkedList->addAtIndex(1, 2);  // linked list becomes 1->2->3
  linkedList->printLinkedList();

  test_x = linkedList->get(1);
  cout << "\ntest_x: " << test_x << endl;            // returns 2
  linkedList->deleteAtIndex(1);  // now the linked list is 1->3
  linkedList->printLinkedList();
  test_x = linkedList->get(1);            // returns 3
  cout << "\ntest_x: " << test_x << endl;
}
