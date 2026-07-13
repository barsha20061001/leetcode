class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        unordered_map<int, int> seen;

        while (n > 0) {
            int state = 0;

            for (int i = 0; i < 8; i++)
                state = (state << 1) | cells[i];
                // Build the binary representation.

            if (seen.count(state)) {
                int cycleLength = seen[state] - n;
                n %= cycleLength;
                // Instead of simulating billions of days, skip entire cycles.
            }

            seen[state] = n;

            if (n == 0)
                break;

            n--;

            vector<int> next(8, 0);

            for (int i = 1; i < 7; i++) {
                if (cells[i - 1] == cells[i + 1])
                    next[i] = 1;
            }

            cells = next;
        }

        return cells;
    }
};