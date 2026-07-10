class Solution {
public:
    int sumOfGoodIntegers(int n, int k) {

        int sum = 0; // Stores the answer.

        int start = max(1, n - k); // Since x must be positive, the starting point is max(1, n - k)
        int end = n + k; // Largest possible value of x.

        for (int x = start; x <= end; x++) { // Check every integer in the valid range.

            if ((n & x) == 0) // Checks whether n and x have no common set bits.
                sum += x;  // Add the compatible number.
        }

        return sum; 
    }
};