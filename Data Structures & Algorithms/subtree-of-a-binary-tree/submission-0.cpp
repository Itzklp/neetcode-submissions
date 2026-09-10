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
    bool same(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) {
            return true;
        }

        if (p == nullptr || q == nullptr) {
            return false;
        }

        if (p->val != q->val) {
            return false;
        }

        return same(p->left, q->left) && same(p->right, q->right);
    }
    bool isSub(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr) {
            return false;
        }

        if (same(root, subRoot)) {
            return true;
        }

        bool left = isSub(root->left, subRoot);
        bool right = isSub(root->right, subRoot);

        return left || right;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return isSub(root, subRoot);
    }
};
