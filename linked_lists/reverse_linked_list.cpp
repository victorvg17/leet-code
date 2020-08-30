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
    ListNode* reverseList(ListNode* head) {
      ListNode* prev = nullptr;
      ListNode* curr = nullptr;
      while (head != nullptr) {
        curr = new ListNode(head->val);
        curr->next = prev;
        prev = curr;
        head = head->next;
      }
      return prev;
    }
};
