class Solution {
public:
long long countGoodSubarrays(vector<int>& nums) {
struct State {
 int value;
int left;
int right;};
 vector<State> previous;
unordered_map<int, int> lastOccurrence;
long long answer = 0;
for (int right = 0; right < nums.size(); right++) {
 vector<State> current;
 auto addState = [&](int value, int left, int end) {
 if (!current.empty() &&
current.back().value == value &&
current.back().right + 1 == left) {
 current.back().right = end;
 } else {
     current.push_back({value, left, end});}};
for (const State& state : previous) {
 addState(state.value | nums[right],
state.left,
state.right);}
addState(nums[right], right, right);
 lastOccurrence[nums[right]] = right;
for (const State& state : current) {
  auto it = lastOccurrence.find(state.value);
 if (it != lastOccurrence.end()) {
 int last = min(state.right, it->second);
if (last >= state.left) {
 answer += last - state.left + 1LL;
}} }
 previous = move(current); }
return answer;
    }
};