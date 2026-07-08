class Solution {
public:
    int reverseBits(int n) {
        int ans = 0;

        for (int i = 0; i < 32; i++) {  //  32 Because an integer has exactly 32 bits.
            ans = (ans << 1)/*Shift every bit one position to the left to create space for the new bit. */ | (n & 1) /* always gives the rightmost bit */;
            // This is bitwise OR. (|) 
            // Shift answer left and append the last bit of n.
            n = n >> 1; // Now remove the last bit from n.
        }

        return ans; // Returns the reversed integer.
    }
};

// Time Complexity
// O(32) = O(1) ( as  32 is a  constant)