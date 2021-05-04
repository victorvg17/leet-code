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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        int list_size = 0;
        ListNode* curr = head;
        while (curr != nullptr) {
            curr = curr->next;
            list_size += 1;
        }
        TreeNode* ret = helper(head, 0, list_size-1);
        return ret;
    }
    TreeNode* helper(ListNode* head, int low, int high) {
        if (low > high) {
            return nullptr;
        }
        int mid = low + (high-low)/2;
        ListNode* curr = head;
        for (int i=0; i<mid; i++) {
            curr = curr->next;
        }
        TreeNode* newb = new TreeNode(curr->val);
        newb->left = helper(head, low, mid-1);
        newb->right = helper(head, mid+1, high);
        return newb;
    }
    
};
