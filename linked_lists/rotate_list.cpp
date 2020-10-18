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
    int getLen(ListNode* head) {
        int len = 0;
        ListNode* curr_ptr = head;
        while (curr_ptr != nullptr) {
            curr_ptr = curr_ptr->next;
            len++;
        }
        return len;
    }

    void joinTailToHead(ListNode* head) {
        ListNode* curr_ptr = head;
        ListNode* prev = nullptr;
        while (curr_ptr != nullptr) {
            prev = curr_ptr;
            curr_ptr = curr_ptr->next;
        }
        prev->next = head;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* curr = head;
        ListNode* prev = nullptr;
        int len = getLen(head);
        if (head == nullptr) {
            return head;
        }
        
        
        if (k >= len) {
            k = k % len;
        }
        
        if (k == 0) {
            //no change
            return head;
        }
        
        //join end of list to begining
        joinTailToHead(head);

        //assign new head and tail
        int diff = len - k;
        cout << "diff : " << diff << endl;
        for (int i=0; i < diff; i++) {
            prev = curr;
            curr = curr->next;
        }
        //now curr points to new head and prev new tail
        prev->next = nullptr;
        return curr;
        
    }
};