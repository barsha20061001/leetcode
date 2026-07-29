class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string s = to_string(num);
        int count = 0;
for (int i = 0; i + k <= s.size(); i++) {
            int value = stoi(s.substr(i, k));
if (value != 0 && num % value == 0)
                count++;
        }return count;
    }
};