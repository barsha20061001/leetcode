class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {

        vector<int> mask(101, 0); // Since the values are only in the range 1 to 100, we can use bit masks.
// Creates an array of size 101 (numbers are 1–100).
        for (int x : nums1)
            mask[x] |= 1; // Set the 1st bit.

        for (int x : nums2)
            mask[x] |= 2;

        for (int x : nums3)
            mask[x] |= 4;

        vector<int> ans;

        for (int i = 1; i <= 100; i++) {
            int cnt = 0;
            int temp = mask[i]; // Copy the mask.

            while (temp) { // Count the number of set bits.
                cnt += temp & 1; // If the last bit is 1, increase the count.
                temp >>= 1; // Move to the next bit.
            }

            if (cnt >= 2) // If the number appeared in at least two arrays, add it.
                ans.push_back(i);
        }

        return ans;
    }
};