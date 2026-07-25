class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> firstIndex;
        firstIndex[0] = -1;

        long long prefixSum = 0;

        for (int i = 0; i < nums.size(); i++) {
            prefixSum += nums[i];
            int remainder = prefixSum % k;

            if (firstIndex.count(remainder)) {
                if (i - firstIndex[remainder] >= 2) {
                    return true;
                }
            } else {
                firstIndex[remainder] = i;
            }
        }

        return false;
    }
};