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
    int pairSum(ListNode* head) {
        vector<int> v;

        while (head != NULL) {
            v.push_back(head->val);
            head = head->next;
        }
 int i = 0, j = v.size() - 1;
        int ans = 0;

        while (i < j) {
            ans = max(ans, v[i] + v[j]);
            i++;
            j--;
        }

        return ans;
    }
};