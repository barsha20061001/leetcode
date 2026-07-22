class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();

        vector<int> previous(n + 1), current(n + 1);

        for (int j = 0; j <= n; j++) {
            previous[j] = j;
        }

        for (int i = 1; i <= m; i++) {
            current[0] = i;

            for (int j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    current[j] = previous[j - 1];
                } else {
                    int insertCharacter = current[j - 1];
                    int deleteCharacter = previous[j];
                    int replaceCharacter = previous[j - 1];

                    current[j] = 1 + min({
                        insertCharacter,
                        deleteCharacter,
                        replaceCharacter
                    });
                }
            }

            previous = current;
        }

        return previous[n];
    }
};