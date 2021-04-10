
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum = 0;
        ListNode* d = new ListNode(0);
        ListNode* runner = d;
        while ((l1 != nullptr) || (l2 != nullptr)) {
            sum = sum/10;
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }
            runner->next = new ListNode(sum%10);
            runner = runner->next;
        }
        if (sum/10 == 1) {
            runner->next = new ListNode(sum/10);
        }
        return d->next;
        
    }
};
