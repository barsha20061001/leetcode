class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int totalSum = nums[0];

        int currentMax = nums[0];
        int maximumSum = nums[0];

        int currentMin = nums[0];
        int minimumSum = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            totalSum += nums[i];

            currentMax = max(nums[i], currentMax + nums[i]);
            maximumSum = max(maximumSum, currentMax);

            currentMin = min(nums[i], currentMin + nums[i]);
            minimumSum = min(minimumSum, currentMin);
        }

        // All elements are negative.
        if (maximumSum < 0)
            return maximumSum;

        return max(maximumSum, totalSum - minimumSum);
    }
};