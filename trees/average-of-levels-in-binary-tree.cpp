
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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode* > Q;
        Q.push(root);
        TreeNode* curr;
        vector<double> res;
        while (Q.size() != 0) {
            int n = Q.size();
            double sum = 0;
            for (int i=0; i<n; i++) {
                curr = Q.front();
                sum += curr->val;
                if (curr->left != nullptr)
                    Q.push(curr->left);
                if (curr->right != nullptr)
                    Q.push(curr->right);
                Q.pop();
            }
            res.push_back(sum/n);
        }
        return res;
    }
};
