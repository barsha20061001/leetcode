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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> matrix(m, vector<int>(n, -1));

        int top = 0;
        int bottom = m - 1;
        int left = 0;
        int right = n - 1;

        while (head != nullptr && top <= bottom && left <= right) {
            // Left to right
            for (int col = left; col <= right && head != nullptr; col++) {
                matrix[top][col] = head->val;
                head = head->next;
            }
            top++;

            // Top to bottom
            for (int row = top; row <= bottom && head != nullptr; row++) {
                matrix[row][right] = head->val;
                head = head->next;
            }
            right--;

            // Right to left
            if (top <= bottom) {
                for (int col = right; col >= left && head != nullptr; col--) {
                    matrix[bottom][col] = head->val;
                    head = head->next;
                }
                bottom--;
            }

            // Bottom to top
            if (left <= right) {
                for (int row = bottom; row >= top && head != nullptr; row--) {
                    matrix[row][left] = head->val;
                    head = head->next;
                }
                left++;
            }
        }

        return matrix;
    }
};