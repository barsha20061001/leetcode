class Solution {
public:
int distinctSubseqII(string s) {
        const long long MOD = 1e9 + 7;
        long long dp[26] = {};
for (char c : s) {
long long sum = 1;
            for (int i = 0; i < 26; i++)
                sum = (sum + dp[i]) % MOD;
            dp[c - 'a'] = sum; }
 long long ans = 0;
for (long long x : dp) ans = (ans + x) % MOD;
 return ans; }
};