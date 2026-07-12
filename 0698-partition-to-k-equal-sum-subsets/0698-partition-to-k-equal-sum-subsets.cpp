class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int total = accumulate(nums.begin(), nums.end(), 0);

        if (total % k != 0)
            return false;
            // If the total sum is not divisible by k, it's impossible to divide into equal-sum subsets.

        int target = total / k;
        sort(nums.rbegin(), nums.rend());

        if (nums[0] > target)
            return false;

        vector<int> subsets(k, 0);

        function<bool(int)> solve = [&](int index) {
            if (index == nums.size())
                return true;

            for (int i = 0; i < k; i++) {
                if (subsets[i] + nums[index] > target)
                    continue;

                subsets[i] += nums[index];

                if (solve(index + 1))
                    return true;

                subsets[i] -= nums[index];

                if (subsets[i] == 0)
                    break;
            }

            return false;
        };

        return solve(0);
    }
};