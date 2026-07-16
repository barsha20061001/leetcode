class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();

        if (n % 2 != 0)
            return false;

        int balance = 0;

        // Left to right:
        // unlocked characters can act as '('
        for (int i = 0; i < n; i++) {
            if (locked[i] == '0' || s[i] == '(')
                balance++;
            else
                balance--;

            if (balance < 0)
                return false;
        }

        balance = 0;

        // Right to left:
        // unlocked characters can act as ')'
        for (int i = n - 1; i >= 0; i--) {
            if (locked[i] == '0' || s[i] == ')')
                balance++;
            else
                balance--;

            if (balance < 0)
                return false;
        }

        return true;
    }
};