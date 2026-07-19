class Solution {
public:
    bool hasSameDigits(string s) {
        while (s.size() > 2) {
            string temp = "";

            for (int i = 0; i < s.size() - 1; i++) {
                int digit = ((s[i] - '0') + (s[i + 1] - '0')) % 10;
                temp += char(digit + '0');
            }

            s = temp;
        }

        return s[0] == s[1];
    }
};