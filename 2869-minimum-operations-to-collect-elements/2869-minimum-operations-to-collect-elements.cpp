class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        // Traverse the array from the end because every operation removes the last element.
        vector<bool> collected(k + 1, false);
        // Creates an array to remember which values from 1 to k have been collected.
        int remaining = k; // Stores how many required values are still missing.
        int operations = 0;

        for (int i = nums.size() - 1; i >= 0; i--) { // Starts from the last element and moves left.
            operations++;

            if (nums[i] <= k && !collected[nums[i]]) {
                // Checks: Is this number among 1 to k? Have we not collected it before?
                collected[nums[i]] = true; // Marks that number as collected.
                remaining--;
            }

            if (remaining == 0)
            // As soon as all values 1, 2, ..., k are collected, return the number of operations.
                return operations;
        }

        return operations;
    }
};