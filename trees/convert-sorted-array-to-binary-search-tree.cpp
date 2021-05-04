
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
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* ret = helper(nums, 0, nums.size()-1);
        return ret;
    }
    TreeNode* helper(vector<int>& nums, int low, int high) {
        if (low > high) {
            return nullptr;
        }
        int mid = low + (high-low)/2;
        TreeNode* newb = new TreeNode(nums[mid]);
        newb->left = helper(nums, low, mid-1);
        newb->right = helper(nums, mid+1, high);
        return newb;
    }
};
