class Solution {
public:
    bool isPrime(int n) {
        if (n < 2) return false;
        if (n == 2) return true;
        if (n % 2 == 0) return false;

        for (int i = 3; i * i <= n; i += 2) {
            if (n % i == 0) return false;
        }

        return true;
    }

    bool completePrime(int num) {
        string s = to_string(num);
        int n = s.size();

        for (int len = 1; len <= n; len++) {
            int prefix = stoi(s.substr(0, len));
            int suffix = stoi(s.substr(n - len, len));

            if (!isPrime(prefix) || !isPrime(suffix)) {
                return false;
            }
        }

        return true;
    }
};