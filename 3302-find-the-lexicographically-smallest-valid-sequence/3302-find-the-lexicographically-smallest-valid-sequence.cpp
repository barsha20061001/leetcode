class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        
        int n = word1.size();
        int m = word2.size();
        vector<int> last(m, -1);

        int i = n - 1;
        int j = m - 1;

        // Match word2 from right to left.
        while (i >= 0 && j >= 0) {
            
            if (word1[i] == word2[j]) {
                last[j] = i;
                j--;
            }

            i--;
        }

       

        vector<int> ans;
        ans.reserve(m);

        bool usedMismatch = false;

        j = 0;

        for (i = 0; i < n && j < m; i++) {

            // Exact match
            if (word1[i] == word2[j]) {
                
                ans.push_back(i);
                j++;
            }

            // Use this position as the one mismatch
            else if (!usedMismatch &&
                     (j == m - 1 || i < last[j + 1])) {
                
                ans.push_back(i);
                usedMismatch = true;
                j++;
            }
        }

        // Couldn't match all characters.
        if (j != m)
            return {};

        return ans;
    }
};