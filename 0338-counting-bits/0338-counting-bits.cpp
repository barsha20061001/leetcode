class Solution {
public:
    vector<int> countBits(int n) { // Returns a vector where , ans[i] = number of set bits in i
        vector<int> ans(n + 1, 0);  // Create a vector of size : n+1 , because we need answers from 0 to n

        for (int i = 1; i <= n; i++) { // Calculate answer for every number.
            ans[i] = ans[i >> 1] + (i & 1); // Extracts the last bit.
        }

        return ans;
    }
};