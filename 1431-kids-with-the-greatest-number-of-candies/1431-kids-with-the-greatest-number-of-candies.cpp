class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int mx = *max_element(candies.begin(), candies.end());
        vector<bool> ans;

        for (int candy : candies) {
            ans.push_back(candy + extraCandies >= mx);
        }

        return ans;
    }
};