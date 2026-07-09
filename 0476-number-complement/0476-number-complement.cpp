class Solution {
public:
    int findComplement(int num) {
        int mask = 1;  // Creates a mask with all 1s.

        while (mask < num) // Keep increasing the mask until it covers all bits of num.
            mask = (mask << 1) | 1;  // This adds one more 1 to the mask.

        return mask ^ num;  // XOR flips the bits of num.
    }
};