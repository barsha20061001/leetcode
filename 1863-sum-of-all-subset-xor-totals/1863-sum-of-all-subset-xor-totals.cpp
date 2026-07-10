class Solution {
public:
    int solve(vector<int>& nums, int index, int currentXor) {
        if (index == nums.size()) // When all elements have been considered, return the XOR of that subset.
            return currentXor;

        int exclude = solve(nums, index + 1, currentXor); // Do not include the current number.

        int include = solve(nums, index + 1, currentXor ^ nums[index]); // Include the current number, so update XOR.

        return exclude + include; // Add the XOR sums from both choices.
    }

    int subsetXORSum(vector<int>& nums) {
        return solve(nums, 0, 0);
    }
};