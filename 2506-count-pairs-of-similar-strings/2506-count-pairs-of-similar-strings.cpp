class Solution {
public:
    int similarPairs(vector<string>& words) {
        unordered_map<int, int> freq; // Stores how many previous words had each character-mask.
        int ans = 0;

        for (string word : words) { 
            int mask = 0; // Creates a fresh bitmask for the current word.

            for (char c : word) { // Checks every character in that word.
                mask |= 1 << (c - 'a'); // Turns on the bit for character c.
            }

            ans += freq[mask]; 
            freq[mask]++; // Record the current word for future comparisons.
        }

        return ans;
    }
};