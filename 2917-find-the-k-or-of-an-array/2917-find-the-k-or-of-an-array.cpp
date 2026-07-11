class Solution {
public:
    int findKOr(vector<int>& nums, int k) {

        int ans = 0;

        for (int bit = 0; bit < 31; bit++) {
            //  31? Because numbers are up to about 10 ^ 9 , which fits within 31 bits (bits 0–30).

            int cnt = 0;

            for (int x : nums) {
                if (x & (1 << bit)) // Checks whether the current bit is 1.
                    cnt++;
            }

            if (cnt >= k) // If at least k numbers have this bit equal to 1,
            // then this bit should appear in the answer.
                ans |= (1 << bit); // Set that bit in ans.
        }

        return ans;
    }
};