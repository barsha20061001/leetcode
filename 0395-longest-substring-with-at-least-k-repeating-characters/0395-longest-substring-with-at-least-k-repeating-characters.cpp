class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.size(), ans = 0;
for (int uniqueTarget = 1; uniqueTarget <= 26; uniqueTarget++) {
            vector<int> freq(26, 0);
            int left = 0, right = 0;
            int unique = 0, countAtLeastK = 0;
while (right < n) {
                int r = s[right++] - 'a';
if (freq[r] == 0) unique++;
                freq[r]++;
                if (freq[r] == k) countAtLeastK++;
while (unique > uniqueTarget) {
                    int l = s[left++] - 'a';
 if (freq[l] == k) countAtLeastK--;
                    freq[l]--;
                    if (freq[l] == 0) unique--;}
if (unique == uniqueTarget && unique == countAtLeastK)
                    ans = max(ans, right - left);}}
return ans; }
};