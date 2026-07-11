class Solution {
public:
    int minChanges(int n, int k) {

        if ((n & k) != k)
        // every 1 bit present in k must already be present in n.
            return -1; // f this is false, return -1.

        return __builtin_popcount(n ^ k);
        // marks the bit positions where n and k differ.
        // Since we already know all 1s of k exist in n, every differing bit is a 1 in n that must be changed to 0.
    }
};