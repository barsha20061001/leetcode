class Solution {
public:
    string toHex(int num) {
        if (num == 0) return "0";

        string hex = "0123456789abcdef";
        string ans = "";

        unsigned int n = num; // For -1, using

        while (n > 0) {
            int digit = n & 15; // Key idea: n & 15 gets the last 4 bits
            ans += hex[digit];  
            n = n >> 4; // Then shift right by 4
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};