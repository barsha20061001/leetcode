class Solution {
public:
    string longestNiceSubstring(string s) {
        string ans = "";

        for (int i = 0; i < s.size(); i++) {
            int lower = 0;
            int upper = 0;

            for (int j = i; j < s.size(); j++) {
                char c = s[j];

                if (islower(c))
                    lower |= 1 << (c - 'a'); // Turns on the bit corresponding to a lowercase character.
                else
                    upper |= 1 << (c - 'A');

                if (lower == upper && j - i + 1 > ans.size()) { // Checks two things: Current substring is nice. It is longer than the best answer found so far.
                    ans = s.substr(i, j - i + 1);
                }
            }
        }

        return ans;
    }
};