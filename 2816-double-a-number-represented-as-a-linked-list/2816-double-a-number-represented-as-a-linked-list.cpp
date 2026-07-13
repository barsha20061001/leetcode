class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        auto reverseList = [](ListNode* node) {
            ListNode* prev = nullptr;

            while (node) {
                ListNode* nextNode = node->next;
                node->next = prev;
                prev = node;
                node = nextNode;
            }

            return prev;
        };

        head = reverseList(head);

        ListNode* curr = head;
        ListNode* last = nullptr;
        int carry = 0;

        while (curr) {
            int sum = curr->val * 2 + carry;

            curr->val = sum % 10;
            carry = sum / 10;

            last = curr;
            curr = curr->next;
        }

        if (carry)
            last->next = new ListNode(carry);

        return reverseList(head);
    }
};