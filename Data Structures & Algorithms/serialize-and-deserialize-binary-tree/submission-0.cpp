#include <ranges>

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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res = "";
        dfsSerialize(root, res);
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        auto nodes = data | views::split(',') | ranges::to<vector<string>>();
        int i = 0;
        return dfsDeserialize(nodes, i);
    }

private:
    void dfsSerialize(TreeNode* node, string& s) {
        if (!node) {
            s += "N,";
            return;
        };

        s += format("{},", node->val);
        dfsSerialize(node->left, s);
        dfsSerialize(node->right, s);
    }

    TreeNode* dfsDeserialize(const vector<string>& nodes, int& i) {
        if (nodes[i] == "N") {
            ++i;
            return nullptr;
        }

        auto node = new TreeNode(stoi(nodes[i]));
        ++i;

        node->left = dfsDeserialize(nodes, i);
        node->right = dfsDeserialize(nodes, i);

        return node;
    }
};
