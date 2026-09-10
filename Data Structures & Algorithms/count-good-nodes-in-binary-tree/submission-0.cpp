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
    int ans = 0;

    void good(TreeNode* root, int maxi) {
        if (root == nullptr) {
            return;
        }

        if (root->val >= maxi) {
            maxi = root->val;
            ans++;
        }

        good(root->right, maxi);
        good(root->left, maxi);
    }
    int goodNodes(TreeNode* root) {
        good(root, root->val);

        return ans;
    }
};
