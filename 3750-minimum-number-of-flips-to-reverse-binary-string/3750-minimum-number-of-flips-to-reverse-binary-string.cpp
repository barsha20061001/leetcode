class Solution {
public:
    int minimumFlips(int n) {
        string s = ""; // Creates an empty string to store the binary representation of n.

        while (n > 0) {
            s += (n & 1) + '0'; // This gets the last binary bit of n and adds it to s.
            // + '0' Converts the integer bit into a character:
            n >>= 1; // Right-shifts n by one position. This removes the rightmost bit.
        }

        reverse(s.begin(), s.end()); 
        // Reverses s to obtain the proper binary representation.

        int flips = 0;
        // Stores the number of positions where the original binary string differs from its reverse.
        int len = s.size();
        // Stores the length of the binary string.

        for (int i = 0; i < len; i++) {
            if (s[i] != s[len - 1 - i])
            // Compares the character at position i with its corresponding character in the reversed string.
                flips++;
        }

        return flips;
    }
};