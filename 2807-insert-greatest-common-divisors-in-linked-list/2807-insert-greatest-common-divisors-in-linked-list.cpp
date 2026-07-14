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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* current = head;

        while (current != nullptr && current->next != nullptr) {
            ListNode* nextNode = current->next;

            int gcdValue = gcd(current->val, nextNode->val);

            current->next = new ListNode(gcdValue);
            current->next->next = nextNode;

            current = nextNode;
        }

        return head;
    }
};