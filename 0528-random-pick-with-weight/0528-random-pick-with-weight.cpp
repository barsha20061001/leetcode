class Solution {
public:
vector<int> prefix;
Solution(vector<int>& w) {
prefix.resize(w.size());
prefix[0] = w[0];
for (int i = 1; i < w.size(); i++)
prefix[i] = prefix[i - 1] + w[i]; }
int pickIndex() {
 int x = rand() % prefix.back() + 1;
return lower_bound(prefix.begin(), prefix.end(), x) - prefix.begin();}
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */