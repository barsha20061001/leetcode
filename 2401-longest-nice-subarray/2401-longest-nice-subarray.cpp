class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int left = 0; // Left pointer of the sliding window.
        int usedBits = 0; // Stores the OR of all numbers currently inside the window.
        int answer = 0; // Stores the maximum window length.

        for (int right = 0; right < nums.size(); right++) {
            // Move the right pointer through the array.
            while ((usedBits & nums[right]) != 0) {
                usedBits ^= nums[left];
                left++;
            }

            usedBits |= nums[right];
            answer = max(answer, right - left + 1);
        }

        return answer;
    }
};