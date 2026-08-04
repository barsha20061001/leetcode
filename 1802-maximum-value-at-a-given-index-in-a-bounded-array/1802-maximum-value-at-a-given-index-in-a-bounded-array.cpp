class Solution {
public:
long long sideSum(long long peak, long long length) {
if (peak > length) {
return (peak - 1 + peak - length) * length / 2; }
return peak * (peak - 1) / 2 + (length - peak + 1);}
int maxValue(int n, int index, int maxSum) {
long long low = 1, high = maxSum;
 while (low <= high) {
long long mid = low + (high - low) / 2;
long long total = mid;
 total += sideSum(mid, index);
 total += sideSum(mid, n - index - 1);
 if (total <= maxSum)
low = mid + 1;
else
high = mid - 1;}
 return high;}
};