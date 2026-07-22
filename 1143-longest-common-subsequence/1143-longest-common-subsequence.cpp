class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();

        vector<int> previous(n + 1, 0);
        vector<int> current(n + 1, 0);

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    current[j] = 1 + previous[j - 1];
                } else {
                    current[j] = max(previous[j], current[j - 1]);
                }
            }

            previous = current;
        }

        return previous[n];
    }
};