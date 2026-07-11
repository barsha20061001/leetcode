class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;

        for (int x : nums) {
            if (x == 2) {
                // Check whether the current number is 2
                ans.push_back(-1); // Store -1 because no answer exists.
                continue;
            }

            int bit = 0;

            while (x & (1 << bit)) { // This loop checks consecutive 1s starting from the least significant bit (LSB).
                bit++;
            }

            ans.push_back(x - (1 << (bit - 1))); // We subtract 2^(bit-1) from x.
            // This turns OFF the highest 1 among the trailing block of consecutive 1s.
        }

        return ans;
    }
};