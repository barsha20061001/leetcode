class Solution {
public:
    bool isPrime(long long n) {
        if (n < 2) return false;
        if (n % 2 == 0) return n == 2;

        for (long long d = 3; d * d <= n; d += 2) {
            if (n % d == 0) return false;
        }

        return true;
    }

    long long sumOfLargestPrimes(string s) {
        set<long long> primes;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            long long value = 0;

            for (int j = i; j < n; j++) {
                value = value * 10 + (s[j] - '0');

                if (isPrime(value)) {
                    primes.insert(value);
                }
            }
        }

        long long answer = 0;
        int count = 0;

        for (auto it = primes.rbegin(); it != primes.rend() && count < 3; ++it) {
            answer += *it;
            count++;
        }

        return answer;
    }
};