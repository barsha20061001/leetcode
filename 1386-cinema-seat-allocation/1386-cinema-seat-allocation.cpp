class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> mp;
        for (auto &seat : reservedSeats) {
            int row = seat[0];
            int s = seat[1];

            mp[row] |= (1 << s);
        }
        long long ans = 2LL * n;

        for (auto &[row, mask] : mp) {
            ans -= 2;
            bool left = (mask & (1 << 2)) == 0 &&
                        (mask & (1 << 3)) == 0 &&
                        (mask & (1 << 4)) == 0 &&
                        (mask & (1 << 5)) == 0;
            bool right = (mask & (1 << 6)) == 0 &&
                         (mask & (1 << 7)) == 0 &&
                         (mask & (1 << 8)) == 0 &&
                         (mask & (1 << 9)) == 0;

            if (left && right) {
                // Both groups can sit
                ans += 2;
            }
            else if (left || right) {
                // Only one of the two outer groups can sit
                ans += 1;
            }
            else {
                // Check middle block: seats 4,5,6,7
                bool middle = (mask & (1 << 4)) == 0 &&
                              (mask & (1 << 5)) == 0 &&
                              (mask & (1 << 6)) == 0 &&
                              (mask & (1 << 7)) == 0;

                if (middle)
                    ans += 1;
            }
        }

        return ans;
    }
};