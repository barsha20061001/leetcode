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
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        ListNode dummy(0, head);
        ListNode* previousGroupEnd = &dummy;
        int requiredLength = 1;

        while (previousGroupEnd->next != nullptr) {
            ListNode* groupStart = previousGroupEnd->next;
            ListNode* groupEnd = groupStart;

            int actualLength = 1;

            while (actualLength < requiredLength &&
                   groupEnd->next != nullptr) {
                groupEnd = groupEnd->next;
                actualLength++;
            }

            ListNode* nextGroupStart = groupEnd->next;

            if (actualLength % 2 == 0) {
                ListNode* previous = nextGroupStart;
                ListNode* current = groupStart;

                while (current != nextGroupStart) {
                    ListNode* nextNode = current->next;
                    current->next = previous;
                    previous = current;
                    current = nextNode;
                }

                previousGroupEnd->next = groupEnd;
                previousGroupEnd = groupStart;
            } else {
                previousGroupEnd = groupEnd;
            }

            requiredLength++;
        }

        return dummy.next;
    }
};