class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {

        vector<int> freq(51, 0);
        // Creates a frequency array. Since the constraints are 1 <= nums[i] <= 50 we need indices 1 to 50.
        int ans = 0;

        for (int x : nums)
            freq[x]++;

        for (int i = 1; i <= 50; i++) {
            if (freq[i] == 2) // If the number appears exactly twice, include it in the XOR.
                ans ^= i; // ans = ans ^ i;
        }

        return ans;
    }
};