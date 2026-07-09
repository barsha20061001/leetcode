class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans = nums.size();  // Store the largest expected number.

        for (int i = 0; i < nums.size(); i++) { // Visit every index.
            ans ^= i;   // XOR current index.
            ans ^= nums[i];  //  XOR current array value.
        }

        return ans;
    }
};