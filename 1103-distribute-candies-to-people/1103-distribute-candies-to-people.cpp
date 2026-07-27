class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> ans(num_people, 0);
        int give = 1, i = 0;
        while (candies > 0) {
            int current = min(give, candies);
            ans[i % num_people] += current;
            candies -= current;
            give++;
            i++;}
        return ans;
    }
};