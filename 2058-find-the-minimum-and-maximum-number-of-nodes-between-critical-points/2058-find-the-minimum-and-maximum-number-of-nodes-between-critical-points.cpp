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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* prev = head;
        ListNode* curr = head->next;

        int index = 1;
        int firstCritical = -1;
        int previousCritical = -1;
        int minDistance = INT_MAX;
        int maxDistance = -1;

        while (curr->next != nullptr) {
            bool isMaximum =
                curr->val > prev->val &&
                curr->val > curr->next->val;

            bool isMinimum =
                curr->val < prev->val &&
                curr->val < curr->next->val;

            if (isMaximum || isMinimum) {
                if (firstCritical == -1) {
                    firstCritical = index;
                } else {
                    minDistance =
                        min(minDistance, index - previousCritical);

                    maxDistance = index - firstCritical;
                }

                previousCritical = index;
            }

            prev = curr;
            curr = curr->next;
            index++;
        }

        if (maxDistance == -1) {
            return {-1, -1};
        }

        return {minDistance, maxDistance};
    }
};