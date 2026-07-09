class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {   // stores how many times each number appears.
        int n = nums.size();  // Stores the size of array.
        vector<int> freq(n + 1, 0);  // Size is n+1 because numbers are from 1 to n.

        for (int x : nums) {  // Loop through every number in nums.
            freq[x]++; // Increase count of that number.
        }

        int duplicate = -1;  // Initially we do not know the duplicate and missing numbers.
        int missing = -1;

        for (int i = 1; i <= n; i++) {
            if (freq[i] == 2) // If a number appears twice, it is the duplicate.
                duplicate = i;

            if (freq[i] == 0) // If a number appears zero times, it is missing.
                missing = i;
        }

        return {duplicate, missing}; // Return answer in required order.
    }
};