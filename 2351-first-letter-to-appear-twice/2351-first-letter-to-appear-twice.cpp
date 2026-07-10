class Solution {
public:
    char repeatedCharacter(string s) {

        int mask = 0; // mask stores which letters have already been seen.

        for (char c : s) { // Visit every character of the string one by one.

            int bit = c - 'a'; // Convert the character into its bit position.

            if (mask & (1 << bit)) // Check whether this character has already been seen.
                return c;

            mask |= (1 << bit); // If the character has not appeared before, mark it as seen.
        }

        return ' ';
    }
};