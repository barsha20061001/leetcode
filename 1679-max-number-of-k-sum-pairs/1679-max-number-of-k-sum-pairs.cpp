class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int operations = 0;

        for (int num : nums) {
            int needed = k - num;

            if (freq[needed] > 0) {
                operations++;
                freq[needed]--;
            } else {
                freq[num]++;
            }
        }

        return operations;
    }
};