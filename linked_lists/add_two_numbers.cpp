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
/* test case */
/* Input: (2 -> 4 -> 3) + (5 -> 6 -> 4) */
/* Output: 7 -> 0 -> 8 */
/* Explanation: 342 + 465 = 807 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      ListNode* p = new ListNode(0);
      ListNode* out = p;
      ListNode* p1 = l1;
      ListNode* p2 = l2;
      int sum = 0;
      int carry = 0;
      int x, y = 0;
      while ((p1 != nullptr) || (p2 != nullptr)) {
        int x = (p1 != nullptr ? p1->val : 0);
        int y = (p2 != nullptr ? p2->val : 0);
        sum = x + y + carry;
        carry = sum/10;
        p->next = new ListNode(sum%10);

        if (p1 != nullptr) {
          p1 = p1->next;
        }
        if (p2 != nullptr) {
          p2 = p2->next;
        }
        p = p->next;
      } //end while

      if (carry != 0) {
        p->next = new ListNode(carry);
      }
      return out->next;
    }
};
