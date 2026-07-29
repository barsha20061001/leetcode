class Solution {
public:
    string fractionAddition(string expression) {
        long long num = 0, den = 1;
        int i = 0, n = expression.size();
while (i < n) {
            int sign = 1;
            if (expression[i] == '+' || expression[i] == '-') {
                if (expression[i] == '-') sign = -1;
                i++;}
 long long a = 0;
            while (isdigit(expression[i]))
                a = a * 10 + (expression[i++] - '0');
i++; // skip '/'
 long long b = 0;
            while (i < n && isdigit(expression[i]))
                b = b * 10 + (expression[i++] - '0');
 a *= sign;
num = num * b + a * den;
            den *= b;
long long g = gcd(abs(num), den);
            num /= g;
            den /= g; }
 return to_string(num) + "/" + to_string(den); }
};