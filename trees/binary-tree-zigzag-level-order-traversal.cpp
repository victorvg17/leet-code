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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > res;
        if (root == nullptr)
            return res;
        queue<TreeNode* >q;
        q.push(root);
        bool rev = true;
        while(!q.empty()) {
            vector<int> level;
            int cnt = q.size();
            for (int i=0; i<cnt; i++) {
                TreeNode* curr = q.front();
                level.push_back(curr->val);
                if (curr->left != nullptr)
                    q.push(curr->left);
                if (curr->right != nullptr)
                    q.push(curr->right);
                q.pop();
            }
            
            rev = !rev;
            if (rev == true) {
                std::reverse(level.begin(), level.end());
                res.push_back(level);
            } else{
                res.push_back(level);
            }
                
        }
        return res;
            
    }
};
