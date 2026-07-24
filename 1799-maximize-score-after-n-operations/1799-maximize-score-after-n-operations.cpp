class Solution {
public:
int maxScore(vector<int>& nums) {
int size = nums.size();
int totalMasks = 1 << size;
vector<int> dp(totalMasks, 0);
for (int mask = 0; mask < totalMasks; mask++) {
int used = __builtin_popcount(mask);
if (used % 2 != 0) continue;
int operation = used / 2 + 1;
for (int i = 0; i < size; i++) {
if (mask & (1 << i)) continue;
for (int j = i + 1; j < size; j++) {
 if (mask & (1 << j)) continue;
 int newMask = mask | (1 << i) | (1 << j);
dp[newMask] = max(
 dp[newMask],
dp[mask] + operation * gcd(nums[i], nums[j]));
 } }}
 return dp[totalMasks - 1];
    }
};