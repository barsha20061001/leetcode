class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int mask = 0;
        int ans = 0;

        for (char c : allowed) { // Go through every allowed character.
            mask |= 1 << (c - 'a'); // Turns ON the bit for character c.
        }

        for (string word : words) {  // Go through every word.
            bool ok = true; // Assume current word is consistent.

            for (char c : word) { // Check every character of the word.
                if ((mask & (1 << (c - 'a'))) == 0) { // Checks whether character c is NOT allowed.
                    ok = false; // Mark word as not consistent.
                    break; // Stop checking this word because one invalid character is enough.
                }
            }

            if (ok) // If word contains only allowed characters, count it.
                ans++;
        }

        return ans;
    }
};