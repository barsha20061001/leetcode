class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        vector<int> prefix(s.size() + 1, 0);
        // Creates a prefix XOR mask array.
       // prefix[i] stores the parity (odd/even frequency) of every character in the prefix s[0...i-1]
        vector<bool> answer;

        for (int i = 0; i < s.size(); i++) {
            int bit = 1 << (s[i] - 'a');
            // Convert the character into one bit.
            prefix[i + 1] = prefix[i] ^ bit;
            // Toggle the bit of the current character.
        }

        for (auto& query : queries) {
            // Process each query separately.
            int left = query[0];
            int right = query[1];
            int k = query[2];
            // Maximum replacements allowed.

            int mask = prefix[right + 1] ^ prefix[left];
            // This gets the parity mask of s[left...right]
            // Why? Exactly like prefix XOR.
            int oddCount = __builtin_popcount(mask);
            // Count how many letters have odd frequency.

            answer.push_back(oddCount / 2 <= k);
        }

        return answer;
    }
};