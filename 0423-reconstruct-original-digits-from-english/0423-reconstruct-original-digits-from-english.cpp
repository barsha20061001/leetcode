class Solution {
public:
string originalDigits(string s) {
vector<int> count(26, 0);
for (char c : s) {
 count[c - 'a']++;}
vector<int> digits(10, 0);
digits[0] = count['z' - 'a']; // zero
digits[2] = count['w' - 'a']; // two
digits[4] = count['u' - 'a']; // four
 digits[6] = count['x' - 'a']; // six
 digits[8] = count['g' - 'a']; // eight
digits[3] = count['h' - 'a'] - digits[8]; // three
 digits[5] = count['f' - 'a'] - digits[4]; // five
 digits[7] = count['s' - 'a'] - digits[6]; // seven
 digits[1] = count['o' - 'a'] - digits[0] - digits[2] - digits[4];
digits[9] = count['i' - 'a'] - digits[5] - digits[6] - digits[8];
 string answer;
 for (int digit = 0; digit <= 9; digit++) {
answer.append(digits[digit], char('0' + digit)); }
 return answer;
    }
};