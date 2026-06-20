/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        unordered_map<Node*, Node*> originalToCopy;
        originalToCopy[nullptr] = nullptr;

        auto original{head};

        while(original) {
            originalToCopy[original] = new Node(original->val);
            original = original->next;
        }

        original = head;
        while (original) {
            auto copy = originalToCopy[original];
            copy->next = originalToCopy[original->next];
            copy->random = originalToCopy[original->random]; 
            original = original->next;
        }

        return originalToCopy[head];
    }
};
