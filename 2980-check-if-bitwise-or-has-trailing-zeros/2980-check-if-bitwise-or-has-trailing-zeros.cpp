class Solution {
public:
    bool hasTrailingZeros(vector<int>& nums) {

        // the last bit of the OR is 0 only if every selected number is even.
   // Since we need to select at least two numbers, we simply need at least two even numbers in the array.

        int even = 0; 

        for (int x : nums) { // Traverse every element of the array.
            if ((x & 1) == 0) // Checks whether x is even.
                even++;
        }

        return even >= 2; // If there are at least two even numbers, return true.
    }
};