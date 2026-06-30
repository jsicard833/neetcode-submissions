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
    bool isValidBST(TreeNode* root) {
        return dfs(root, numeric_limits<int>::min(), numeric_limits<int>::max());
    }

private:
    bool dfs(TreeNode* node, int minVal, int maxVal) {
        if (!node) return true;

        if (node->val <= minVal || node->val >= maxVal) return false;

        return dfs(node->left, minVal, node->val) && dfs(node->right, node->val, maxVal);
    }
};
