class Solution {
public:
    int smallestNumber(int n) {

        int x = 1; // Start with the smallest valid number.

        while (x < n) {
            x = (x << 1) | 1;
            // This generates the next number consisting of all 1s.
        }

        return x;
    }
};