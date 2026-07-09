class Solution {
public:
    char findTheDifference(string s, string t) {
        char ans = 0; // Start with ASCII value 0.

        for (char c : s) // Visit every character of s.
            ans ^= c; // XOR the current character.

        for (char c : t) // Visit every character of t.
            ans ^= c;  // 

        return ans; // Return the extra character.
    }
};