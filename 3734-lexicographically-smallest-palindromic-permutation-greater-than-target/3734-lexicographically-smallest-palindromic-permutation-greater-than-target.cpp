class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int cnt[26] = {};
        for (char c : s)
            cnt[c - 'a']++;
        int odd = 0, mid = -1;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2) {
                odd++;
                mid = i;}  }
 if (odd > 1)
return "";
 int n = s.size();
        int m = n / 2;
        for (int i = 0; i < 26; i++)
            cnt[i] /= 2;
        auto makePalindrome = [&](string half) {
            string res = half;

            if (mid != -1)
                res += char('a' + mid);
            string rev = half;
            reverse(rev.begin(), rev.end());
            return res + rev; };
   string half;
 for (int i = 0; i < m; i++) {
            int x = target[i] - 'a';
  if (cnt[x] > 0) {
                cnt[x]--;
                half += target[i];
            } else {
                for (int j = x + 1; j < 26; j++) {
                    if (cnt[j] > 0) {
                        string ans = half;
                        ans += char('a' + j);
                        cnt[j]--;
                        for (int k = 0; k < 26; k++)
                            ans += string(cnt[k], char('a' + k));
                        return makePalindrome(ans); }  }
                break;
            } }
        if ((int)half.size() == m) {
            string p = makePalindrome(half);
            if (p > target)
                return p; }
        while (!half.empty()) {
            int x = half.back() - 'a';
            half.pop_back();
            cnt[x]++;
            for (int j = x + 1; j < 26; j++) {
                if (cnt[j] > 0) {
                    string ans = half;
                    ans += char('a' + j);
                    cnt[j]--;
                    for (int k = 0; k < 26; k++)
                        ans += string(cnt[k], char('a' + k));
                    return makePalindrome(ans);
                } }}
        return "";}
};