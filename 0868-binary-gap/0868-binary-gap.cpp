class Solution {
public:
    int binaryGap(int n) {
        int last = -1; // Stores position of previous 1.
        int ans = 0; // Stores maximum gap.
        int pos = 0; // Current bit position from right side.

        while (n > 0) { 
            if (n & 1) { // Checks if current last bit is 1.
                if (last != -1) 
                    ans = max(ans, pos - last); // If we saw a 1 before, calculate distance.

                last = pos; // Update latest position of 1.
            }

            n >>= 1; // Remove current last bit.
            pos++; // Move to next bit position.
        }

        return ans;
    }
};