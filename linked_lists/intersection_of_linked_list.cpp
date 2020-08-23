/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
      map<ListNode*, int> address_book;
      ListNode* runner = headA;
      while (runner != nullptr) {
        address_book.insert(pair<ListNode*, int>
                            (runner, runner->val));
        runner = runner->next;
      }

      runner = headB;
      while (runner != nullptr) {
        auto it = address_book.find(runner);
        if (it != address_book.end()) {
          return it->first;
        }
        runner = runner->next;
      }
      return nullptr;
    }
};
