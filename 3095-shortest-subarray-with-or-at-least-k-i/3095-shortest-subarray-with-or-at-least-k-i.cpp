class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = n + 1; // Stores the shortest valid subarray length.

        for (int i = 0; i < n; i++) {
            int currentOR = 0; // Stores the OR of the current subarray starting at index i.

            for (int j = i; j < n; j++) {
                currentOR |= nums[j];  // It adds the current element to the subarray OR.

                if (currentOR >= k) { // Checks whether the current subarray is special.
                    ans = min(ans, j - i + 1); // Updates the minimum length.
                    break;
                }
            }
        }

        return ans == n + 1 ? -1 : ans; // If ans was never updated, return -1. 
        // Otherwise, return the shortest length.
    }
};