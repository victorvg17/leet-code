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
    bool isPalindrome(ListNode* head) {
      ListNode* reversed_ptr = reverseList(head);
      bool check_palin = false;

      while (reversed_ptr != nullptr) {
        if (head->val != reversed_ptr->val) {
          return false;
        }
        head = head->next;
        reversed_ptr = reversed_ptr->next;
      }
      return true;
    }

    ListNode* reverseList(ListNode* head) {
      ListNode* curr = nullptr;
      ListNode* prev = nullptr;
      while (head != nullptr) {
        curr = new ListNode(head->val);
        curr->next = prev;
        prev = curr;
        head = head->next;
      }
      return prev;
    }
};
