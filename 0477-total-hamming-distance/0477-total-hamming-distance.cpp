class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int n = nums.size();
        int answer = 0;

        for (int bit = 0; bit < 31; bit++) {
            int ones = 0;

            for (int num : nums) {
                if (num & (1 << bit))
                // Checks whether the current bit is 1.
                    ones++;
            }

            int zeros = n - ones;
            // The remaining numbers have 0 at this bit.
            answer += ones * zeros;
            // Every number with bit 1 differs from every number with bit 0.
            // So the contribution of this bit is ones × zeros
        }

        return answer;
    }
};