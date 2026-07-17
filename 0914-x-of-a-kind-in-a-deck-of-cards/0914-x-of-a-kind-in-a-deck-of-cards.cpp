class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> freq;

        for (int card : deck)
            freq[card]++;

        int commonGCD = 0;

        for (auto& entry : freq)
            commonGCD = gcd(commonGCD, entry.second);

        return commonGCD > 1;
    }
};