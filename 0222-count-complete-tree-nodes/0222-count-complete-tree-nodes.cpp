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
    int leftHight(TreeNode* root) {
        int hight = 0;

        while (root) {
            hight++;
            root = root->left;
        }

        return hight;
    }

    int rightHight(TreeNode* root) {
        int hight = 0;

        while (root) {
            hight++;
            root = root->right;
        }

        return hight;
    }

public:
    int countNodes(TreeNode* root) {
        if (root == nullptr)
            return 0;

        int lh = leftHight(root);
        int rh = rightHight(root);

        if (lh == rh) {
            return (1 << lh) - 1;
        }

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};