/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
    int findSum(TreeNode* root, int& ans) {
        if (root == nullptr)
            return 0;

        int leftSum = findSum(root->left, ans);
        int rightSum = findSum(root->right, ans);

        ans += abs(leftSum - rightSum);

        return root->val + leftSum + rightSum;
    }

public:
    int findTilt(TreeNode* root) {
        int ans = 0;
        findSum(root, ans);

        return ans;
    }
};