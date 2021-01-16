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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> out;
        stack<TreeNode*> my_stack;
        TreeNode* curr = root;
        if (root == nullptr){
            return out;
        }
        while ((curr != nullptr) || !my_stack.empty()) {
            while (curr != nullptr){
                my_stack.push(curr);
                curr = curr->left;
            }
            curr = my_stack.top();
            my_stack.pop();
            out.push_back(curr->val);
            curr = curr->right;
        }
        return out;
    }
};