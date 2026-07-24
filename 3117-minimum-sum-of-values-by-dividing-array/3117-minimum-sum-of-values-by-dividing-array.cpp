class Solution {
public:
int minimumValueSum(vector<int>& nums, vector<int>& andValues) {
const int ALL_BITS = (1 << 17) - 1;
const int INF = 1e9;
int m = andValues.size();
vector<unordered_map<int, int>> dp(m + 1);
dp[0][ALL_BITS] = 0;
for (int num : nums) {
vector<unordered_map<int, int>> nextDP(m + 1);
for (int j = 0; j < m; j++) {
for (auto& [currentAnd, cost] : dp[j]) {
int newAnd = currentAnd & num;
if ((newAnd & andValues[j]) != andValues[j])
continue;
auto it = nextDP[j].find(newAnd);
if (it == nextDP[j].end())
    nextDP[j][newAnd] = cost;
else
 it->second = min(it->second, cost);
if (newAnd == andValues[j]) {
int newCost = cost + num;
auto closeIt = nextDP[j + 1].find(ALL_BITS);
if (closeIt == nextDP[j + 1].end())
 nextDP[j + 1][ALL_BITS] = newCost;
 else
 closeIt->second = min(closeIt->second, newCost);
 }}}
dp = move(nextDP);}
auto it = dp[m].find(ALL_BITS);
return it == dp[m].end() ? -1 : it->second;
    }
};