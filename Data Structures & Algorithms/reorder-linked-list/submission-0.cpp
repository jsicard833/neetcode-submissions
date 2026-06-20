#include <utility>

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
    void reorderList(ListNode* head) {
        ListNode* slow{head}, *fast{head};
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* mid = slow->next;
        slow->next = nullptr;

        ListNode* currA{head};
        ListNode* currB{reverseList(mid)};

        while (currB) {
            ListNode* nextA = currA->next;
            ListNode* nextB = currB->next;

            currA->next = currB;
            currB->next = nextA;

            currA = nextA;
            currB = nextB;
        }
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* prev{nullptr};
        while (head) {
            head = exchange(head->next, exchange(prev, head));
        }
        return prev;
    }
};
