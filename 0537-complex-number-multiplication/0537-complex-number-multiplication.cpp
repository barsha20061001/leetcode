class Solution {
public:
pair<int, int> parse(string s) {
int pos = s.find('+');
int real = stoi(s.substr(0, pos));
int imag = stoi(s.substr(pos + 1, s.size() - pos - 2));
return {real, imag};}
string complexNumberMultiply(string num1, string num2) {
auto [a, b] = parse(num1);
 auto [c, d] = parse(num2);
int real = a * c - b * d;
int imag = a * d + b * c;
return to_string(real) + "+" + to_string(imag) + "i";}
};