class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        unordered_set<int> factors;

        for (int num : nums) {
            for (int divisor = 2; divisor * divisor <= num; divisor++) {
                if (num % divisor == 0) {
                    factors.insert(divisor);

                    while (num % divisor == 0)
                        num /= divisor;
                }
            }

            if (num > 1)
                factors.insert(num);
        }

        return factors.size();
    }
};