class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        int ans = 0; // Stores the maximum XOR found so far.

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i; j < nums.size(); j++) {
                int x = nums[i]; // Store the current pair.
                int y = nums[j];

                if (abs(x - y) <= min(x, y)) { // Checks whether (x, y) is a strong pair.
                    ans = max(ans, x ^ y); // If it is a strong pair,
                }
            }
        }

        return ans;
    }
};