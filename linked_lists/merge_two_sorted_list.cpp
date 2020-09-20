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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
      ListNode* p1 = l1;
      ListNode* p2 = l2;
      int val1, val2;
      ListNode* p = new ListNode(0);
      ListNode* merged_list = p;
      while ((p1 != nullptr) && (p2 != nullptr)) {
          val1 = p1->val;
          val2 = p2->val;
          if (val1 <= val2) {
            p->next = p1;
            p1 = p1->next;
          } else {
            p->next = p2;
            p2 = p2->next;
          }
          p = p->next;
      }
      //if loop exited, check for p1 and p2 seperately.
      if (p1 == nullptr) {
        p->next = p2;
      }
      else if (p2 == nullptr){
        p->next = p1;
      }
      return merged_list->next;
    }
};
