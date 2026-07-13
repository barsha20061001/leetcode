class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        map<vector<int>, int> memo;

        function<int(vector<int>&)> solve = [&](vector<int>& remaining) {
            if (memo.count(remaining))
                return memo[remaining];
                // Return the stored minimum cost. No recalculation.

            int cost = 0;

            for (int i = 0; i < price.size(); i++)
                cost += remaining[i] * price[i];
                // Buy all remaining items at normal price.

            for (auto &offer : special) {
                // Now try every special offer.
                vector<int> next = remaining;
                bool valid = true;

                for (int i = 0; i < price.size(); i++) {
                    if (offer[i] > next[i]) {
                        valid = false;
                        break;
                    }
                    next[i] -= offer[i];
                }

                if (valid)
                    cost = min(cost, offer.back() + solve(next));
            }

            return memo[remaining] = cost;
        };

        return solve(needs);
    }
};