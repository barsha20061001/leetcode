class Solution {
public:
    bool divideArray(vector<int>& nums) {
        vector<int> freq(501, 0); // Creates a frequency array for values 1 to 500.

        for (int x : nums) {  // Counts how many times each number appears.
            freq[x]++;
        }

        for (int i = 1; i <= 500; i++) {
            if (freq[i] % 2 != 0) // Checks whether any number appears an odd number of times.
                return false; // If any odd frequency is found, pairing is impossible.
        }

        return true; // If every frequency is even, all numbers can be paired.
    }
};

// Time: O(n + 500)
// Space: O(501) = O(1)
