class Solution {
public:
    bool isPrime(int n) {
        if (n < 2)
            return false;

        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0)
                return false;
        }

        return true;
    }

    bool checkPrimeFrequency(vector<int>& nums) {
        unordered_map<int, int> freq;

        for (int num : nums)
            freq[num]++;

        for (auto &it : freq) {
            if (isPrime(it.second))
                return true;
        }

        return false;
    }
};