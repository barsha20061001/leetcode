class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;  // Initially no set bits have been counted.

        while (n) { // This loop runs until n becomes zero.   
            count += (n & 1); // This checks whether the last bit is 1.
            n = n >> 1; // Right shift removes the last bit.
        }

        return count;
    }
};