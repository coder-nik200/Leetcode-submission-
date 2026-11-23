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
    int findLen(TreeNode* root, int& ans) {
        if (root == nullptr)
            return 0;

        int left = findLen(root->left, ans);
        int right = findLen(root->right, ans);

        int leftPath = 0;
        int rightPath = 0;

        if (root->left && root->left->val == root->val) {
            leftPath = left + 1;
        }

        if (root->right && root->right->val == root->val) {
            rightPath = right + 1;
        }

        ans = max(ans, leftPath + rightPath);

        return max(leftPath, rightPath);
    }

public:
    int longestUnivaluePath(TreeNode* root) {
        int ans = 0;
        findLen(root, ans);

        return ans;
    }
};