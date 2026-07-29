class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        long long sum = 0, current = 0;
        int n = nums.size();
 for (int i = 0; i < n; i++) {
            sum += nums[i];
            current += 1LL * i * nums[i];}
long long answer = current;
for (int k = 1; k < n; k++) {
            current = current + sum - 1LL * n * nums[n - k];
            answer = max(answer, current);
        }return (int)answer;}
};