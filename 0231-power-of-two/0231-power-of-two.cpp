class Solution {  // A power of 2 always has exactly one set bit (1).
public:
    bool isPowerOfTwo(int n) {
        return n > 0 /* 0 is not a power of 2. Also negative numbers are not powers of 2. */ && (n & (n - 1)) == 0;
        // removes the rightmost set bit (rightmost 1) from n.
    }
};
