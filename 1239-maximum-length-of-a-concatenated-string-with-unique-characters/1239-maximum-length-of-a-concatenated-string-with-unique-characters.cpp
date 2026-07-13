class Solution {
public:
    int maxLength(vector<string>& arr) {
        vector<int> masks;

        for (string& word : arr) {
            int mask = 0;
            bool valid = true;
            // Assume the current word has unique characters. If we find duplicates, we'll make it false.

            for (char ch : word) {
                int bit = 1 << (ch - 'a');
                // Convert the character into one bit.

                if (mask & bit) {
                    valid = false;
                    break;
                }

                mask |= bit;
            }

            if (valid)
                masks.push_back(mask);
        }

        int answer = 0;

        function<void(int, int)> solve = [&](int index, int usedMask) {
            answer = max(answer, __builtin_popcount(usedMask));

            for (int i = index; i < masks.size(); i++) {
                if ((usedMask & masks[i]) == 0)
                    solve(i + 1, usedMask | masks[i]);
            }
        };

        solve(0, 0);
        return answer;
    }
};