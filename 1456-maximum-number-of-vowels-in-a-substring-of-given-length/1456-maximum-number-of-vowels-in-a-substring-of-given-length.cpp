class Solution {
public:
    int maxVowels(string s, int k) {
        auto isVowel = [](char ch) {
            return ch == 'a' || ch == 'e' || ch == 'i' ||
                   ch == 'o' || ch == 'u';
        };

        int count = 0;

        for (int i = 0; i < k; i++) {
            if (isVowel(s[i]))
                count++;
        }

        int answer = count;

        for (int i = k; i < s.size(); i++) {
            if (isVowel(s[i]))
                count++;

            if (isVowel(s[i - k]))
                count--;

            answer = max(answer, count);
        }

        return answer;
    }
};