class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (__builtin_popcount(i) == k) // Counts the number of 1s in the binary representation of i.
            // Checks if the current index has exactly k set bits.
                sum += nums[i]; 
        }

        return sum;
    }
};