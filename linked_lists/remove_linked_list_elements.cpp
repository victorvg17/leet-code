/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
      int curr_val = 0;
      ListNode* curr_pointer = head;
      ListNode* prev = head;
      //check if first element matches int value
      if (head == nullptr) {
        return nullptr;
      }

      while ((head != nullptr) && (head->value == val)) {
        head = head->next;
      }
      
      while (curr_pointer != nullptr) {
        curr_val = curr_pointer->val;
        if (curr_val == val) {
          prev->next = curr_pointer->next;
        } else {
          prev = curr_pointer;
        }

        curr_pointer = curr_pointer->next;
      }
      return head;
    }
};
