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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;

        unordered_map<int, ListNode*> lastNode;
        int prefixSum = 0;

        // Store the last node where each prefix sum occurs
        for (ListNode* curr = &dummy; curr != nullptr; curr = curr->next) {
            prefixSum += curr->val;
            lastNode[prefixSum] = curr;
        }

        prefixSum = 0;

        // Skip every zero-sum sequence
        for (ListNode* curr = &dummy; curr != nullptr; curr = curr->next) {
            prefixSum += curr->val;
            curr->next = lastNode[prefixSum]->next;
        }

        return dummy.next;
    }
};