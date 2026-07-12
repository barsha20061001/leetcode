class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> current;

        function<void(int)> solve = [&](int index) {
            // Creates a recursive lambda function.
            // index tells from where we can pick the next element.
            // [&] means capture all outside variables (nums, ans, current) by reference.
            if (current.size() >= 2)
            // If the current subsequence has at least 2 elements, store it.
                ans.push_back(current);

            unordered_set<int> used;

            for (int i = index; i < nums.size(); i++) {

                if (used.count(nums[i]))
                    continue;
                    // If this value has already been chosen at this level, skip it.

                if (!current.empty() && nums[i] < current.back())
                // Checks whether adding nums[i] would violate the non-decreasing condition.
                    continue;

                used.insert(nums[i]);
                current.push_back(nums[i]);

                solve(i + 1);
                // Continue recursion.
                current.pop_back();
            }
        };

        solve(0);
        return ans;
    }
};