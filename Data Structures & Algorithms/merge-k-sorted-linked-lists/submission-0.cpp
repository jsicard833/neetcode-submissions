/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;

        for (auto i{1}; i < lists.size(); ++i) {
            lists[0] = mergeTwoLists(lists[0], lists[i]);
        }

        return lists[0];
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy;
        ListNode* node = &dummy;
        ListNode* a = list1;
        ListNode* b = list2;
        
        while (a && b) {
            if (a->val <= b->val) {
                node->next = a;
                a = a->next;
            } else {
                node->next = b;
                b = b->next;
            }
            node = node->next;
        }

        node->next = a ? a : b;

        return dummy.next;
    }
};
