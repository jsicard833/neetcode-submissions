struct TrieNode {
    TrieNode() = default;

    TrieNode* children[26] {};
    bool isWordEnd = false;
};

class PrefixTree {
public:
    PrefixTree() {
        root = new TrieNode;
    }

    ~PrefixTree() {
        clear(root);
    }
    
    void insert(string word) {
        auto node = root;
        for (auto c : word) {
            int idx = c - 'a';
            
            if (!node->children[idx]) {
                node->children[idx] = new TrieNode;
            }

            node = node->children[idx];
        }
        node->isWordEnd = true;
    }
    
    bool search(string word) {
        auto node = root;
        for (auto c : word) {
            int idx = c - 'a';

            if (!node->children[idx]) {
                return false;
            }

            node = node->children[idx];
        }
        return node->isWordEnd;
    }
    
    bool startsWith(string prefix) {
        auto node = root;
        for (auto c : prefix) {
            int idx = c - 'a';

            if (!node->children[idx]) {
                return false;
            }

            node = node->children[idx];
        }
        return true;
    }

private:
    void clear(TrieNode* node) {
        if (!node) return;
        for (int i = 0; i < 26; ++i) {
            clear(node->children[i]);
        }
        delete node;
    }

    TrieNode* root;
};
