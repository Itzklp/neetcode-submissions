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
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int preStart, int preEnd,
                    int inStart, int inEnd) {
        if (preStart > preEnd || inStart > inEnd) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[preStart]);

        int mid = inStart;

        while (inorder[mid] != preorder[preStart]) {
            mid++;
        }

        int leftSize = mid - inStart;

        root->left = build(preorder, inorder, preStart + 1, preStart + leftSize, inStart, mid - 1);

        root->right = build(preorder, inorder, preStart + leftSize + 1, preEnd, mid + 1, inEnd);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
};