class Solution {
public:
    int numPrimeArrangements(int n) {
        const long long MOD = 1000000007;

        auto isPrime = [](int x) {
            if (x < 2) return false;
            for (int i = 2; i * i <= x; i++)
                if (x % i == 0) return false;
            return true;
        };

        int primes = 0;

        for (int i = 1; i <= n; i++)
            if (isPrime(i))
                primes++;

        long long ans = 1;

        for (int i = 2; i <= primes; i++)
            ans = ans * i % MOD;

        for (int i = 2; i <= n - primes; i++)
            ans = ans * i % MOD;

        return ans;
    }
};