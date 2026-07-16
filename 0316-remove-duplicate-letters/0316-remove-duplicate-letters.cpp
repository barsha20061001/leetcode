class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> lastIndex(26);
        vector<bool> inStack(26, false);
        stack<char> st;

        for (int i = 0; i < s.size(); i++)
            lastIndex[s[i] - 'a'] = i;

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];

            if (inStack[c - 'a'])
                continue;

            while (!st.empty() &&
                   st.top() > c &&
                   lastIndex[st.top() - 'a'] > i) {
                inStack[st.top() - 'a'] = false;
                st.pop();
            }

            st.push(c);
            inStack[c - 'a'] = true;
        }

        string ans = "";
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};