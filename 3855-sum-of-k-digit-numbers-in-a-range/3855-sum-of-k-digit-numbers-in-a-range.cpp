class Solution {
private:
static constexpr long long MOD = 1'000'000'007;
long long power(long long base, long long exponent) {
long long result = 1;
while (exponent > 0) {
if (exponent & 1) {
result = result * base % MOD; }
base = base * base % MOD;
exponent >>= 1;}
return result;}
public:
int sumOfNumbers(int l, int r, int k) {
long long choices = r - l + 1;
long long digitSum = 1LL * (l + r) * choices / 2 % MOD;
long long combinations = power(choices, k - 1);
long long placeValueSum =
(power(10, k) - 1 + MOD) % MOD * power(9, MOD - 2) % MOD;
return digitSum * combinations % MOD * placeValueSum % MOD;
    }
};