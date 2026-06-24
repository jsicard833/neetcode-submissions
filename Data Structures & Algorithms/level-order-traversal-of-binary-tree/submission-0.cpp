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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};

        vector<vector<int>> res;
        queue<TreeNode*> nodeQueue;

        nodeQueue.push(root);

        while (!nodeQueue.empty()) {
            vector<int> level;
            int size = nodeQueue.size();

            for (int i = size; i > 0; --i) {
                TreeNode* current = nodeQueue.front();
                nodeQueue.pop();
                if (current) {
                    level.push_back(current->val);
                    nodeQueue.push(current->left);
                    nodeQueue.push(current->right);
                }
            }
            if (!level.empty()) {
                res.push_back(level);
            }
        }

        return res;
    }
};
