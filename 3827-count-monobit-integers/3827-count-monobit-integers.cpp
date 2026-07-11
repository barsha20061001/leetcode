class Solution {
public:
    int countMonobit(int n) {
        // A binary representation (without leading zeros) always starts with 1 (except for 0).

        int count = 1;      // Count 0
        
        int x = 1;          // First monobit number: 1
       // Start with 1 because 0 is always a Monobit integer.

        while (x <= n) {
            // Keep generating Monobit numbers until they become larger than n.
            count++;
            x = (x << 1) | 1; // Generate the next Monobit number.
        }

        return count;
    }
};