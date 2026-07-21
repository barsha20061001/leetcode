class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());

        int m = potions.size();
        vector<int> pairs;

        for (long long spell : spells) {
            long long required = (success + spell - 1) / spell;

            int index = lower_bound(potions.begin(), potions.end(), required)
                        - potions.begin();

            pairs.push_back(m - index);
        }

        return pairs;
    }
};