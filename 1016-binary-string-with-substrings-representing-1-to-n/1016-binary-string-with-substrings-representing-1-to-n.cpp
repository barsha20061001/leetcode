class Solution {
public:
    bool queryString(string s, int n) {
        for (int num = 1; num <= n; num++) {
            string binary = "";
            // Stores the binary representation of the current number.

            int value = num;
            // Make a copy. We'll convert this copy into binary.

            while (value > 0) {
                binary += (value % 2) + '0';

                value /= 2; // Remove the last binary digit.
            }

            reverse(binary.begin(), binary.end());

            if (s.find(binary) == string::npos)
                return false;
        }

        return true;
    }
};