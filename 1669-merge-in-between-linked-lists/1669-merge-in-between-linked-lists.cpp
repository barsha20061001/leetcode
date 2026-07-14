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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* beforeA = list1;

        // Move to node at index a - 1
        for (int i = 0; i < a - 1; i++) {
            beforeA = beforeA->next;
        }

        ListNode* afterB = beforeA;

        // Move to node at index b + 1
        for (int i = 0; i < b - a + 2; i++) {
            afterB = afterB->next;
        }

        // Connect node before index a to list2
        beforeA->next = list2;

        // Find the last node of list2
        ListNode* tail = list2;
        while (tail->next != nullptr) {
            tail = tail->next;
        }

        // Connect list2's last node to node after index b
        tail->next = afterB;

        return list1;
    }
};