class Solution {
public:
    int minBitFlips(int start, int goal) {
        int x = start ^ goal; // Stores all differing bit positions.
        // start ^ goal has a 1 exactly where the two numbers differ.
        int count = 0; // Stores the number of required flips.

        while (x > 0) {  // Processes all bits of x.
            count += x & 1; // Checks the last bit: If it is 1, add one. If it is 0, add zero.
            x >>= 1; // Removes the last bit by shifting right.
        }
 
        return count; 
    }
};

// Time complexity: O(log n)
// Space complexity: O(1)