class Solution {
public:
    vector<int> evenOddBit(int n) {

        int even = 0; // Counts 1s at even indices.
        int odd = 0;
        int index = 0; // Stores the current bit position.

        while (n > 0) {  // Process every bit until the number becomes 0.

            if (n & 1) {  //  Check whether the current (rightmost) bit is 1.
                if (index % 2 == 0)
                    even++;
                else
                    odd++;
            }

            n >>= 1; // Remove the last bit.
            index++;
        }

        return {even, odd};
    }
};