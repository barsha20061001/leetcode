class Solution {
public:
long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
int n = nums.size();
 int right = n - 1;
long long operations = 0;
long long answer = 0;
deque<int> dq;
for (int left = n - 1; left >= 0; left--) {
 while (!dq.empty() && nums[dq.back()] < nums[left]) {
int index = dq.back();
dq.pop_back();
 int nextIndex = dq.empty() ? right + 1 : dq.back();
operations += 1LL * (nextIndex - index) *
      (nums[left] - nums[index]);}
dq.push_back(left);
 while (operations > k) {
operations -= nums[dq.front()] - nums[right];
if (dq.front() == right) {
dq.pop_front();}
 right--;}
 answer += right - left + 1;}
 return answer;
    }
};