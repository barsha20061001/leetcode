class Solution {
public:
    int numberOfSteps(int num) {

        int steps = 0;

        while (num > 0) { // Keep performing operations until the number becomes 0.

            if (num & 1) // Checks whether the number is odd.
                num--; // If the number is odd, subtract 1.
            else
                num >>= 1; // If the number is even, divide by 2. >>= 1 means right shift by one bit.

            steps++; // Increase the operation count after every step.
        }

        return steps;
    }
};

// Time: O(log n) (each division by 2 removes one binary bit) ; Space: O(1)