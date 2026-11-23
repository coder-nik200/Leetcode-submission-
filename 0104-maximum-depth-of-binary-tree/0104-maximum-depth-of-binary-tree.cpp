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
public:
    int maxDepth(TreeNode* root) {
        // Recursive solution:
        if (root == nullptr)
            return 0;

        int left = maxDepth(root->left);
        int right = maxDepth(root->right);

        return 1 + max(left, right);

        // Level ordering solution:
        // if (root == nullptr)
        //     return {};

        // queue<TreeNode*> q;
        // q.push(root);
        // int len = 0;

        // while (!q.empty()) {
        //     int size = q.size();

        //     for (int i = 0; i < size; i++) {
        //         TreeNode* curr = q.front();
        //         q.pop();

        //         if (curr->left != nullptr) {
        //             q.push(curr->left);
        //         }
        //         if (curr->right != nullptr) {
        //             q.push(curr->right);
        //         }
        //     }

        //     len++;
        // }

        // return len;
    }
};