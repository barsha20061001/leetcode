
/** A number is a power of 4 if:

It is positive.
It has exactly one set bit (so it's a power of 2).
 That set bit is in an even position  **/

class Solution {
public:
    bool isPowerOfFour(int n) {
        return n > 0 &&   // Rejects : 0 , Negative numbers
               (n & (n - 1)) == 0 &&  // This checks whether there is exactly one set bit.
               (n & 0x55555555);  // Only even bit positions are 1.
    }
};