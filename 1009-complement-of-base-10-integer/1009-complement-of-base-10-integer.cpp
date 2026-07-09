class Solution {
public:
    int bitwiseComplement(int n) { // Function takes an integer n and returns its complement.

        if (n == 0)
            return 1; // complement of 0 is 1 

        int mask = 1; // Create a mask.

        while (mask < n) // Keep increasing the mask until it has the same number of bits as n
            mask = (mask << 1) | 1; // 

        return mask ^ n; // XOR flips every bit.
    }
};