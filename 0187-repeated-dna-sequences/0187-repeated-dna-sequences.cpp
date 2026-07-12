class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string> seen;
        unordered_set<string> repeated;

        for (int i = 0; i + 10 <= s.size(); i++) {
            string current = s.substr(i, 10);

            if (seen.count(current))
                repeated.insert(current);
            else
                seen.insert(current);
        }

        return vector<string>(repeated.begin(), repeated.end());
    }
};