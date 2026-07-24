class Solution {
public:
long long nthSmallest(long long n, int k) {
long long combinations[50][51] = {};
for (int i = 0; i < 50; i++) {
 combinations[i][0] = 1;
for (int j = 1; j <= i; j++) {
  combinations[i][j] =
 combinations[i - 1][j - 1] +
combinations[i - 1][j];
}}
long long answer = 0;
for (int bit = 49; bit >= 0; bit--) {
if (n > combinations[bit][k]) {
 n -= combinations[bit][k];
answer |= (1LL << bit);
k--;
 if (k == 0) break;}}
 return answer;
    }
};