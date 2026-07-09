class Solution {
public:
    bool hasAlternatingBits(int n) {

        int prev = n & 1; // & 1 extracts the last bit.
        n >>= 1; // Remove last bit, Right shift by one.

        while (n) {   // 
            int curr = n & 1; // Get current last bit

            if (curr == prev) // If two adjacent bits are same, hen bits are not alternating.
                return false;

            prev = curr; // Update previous bit
            n >>= 1; // Again remove the last bit.
        }

        return true;
    }
};