class Solution {
public:
    
    int factor[10][4] = {
        {0, 0, 0, 0}, // 0
        {0, 0, 0, 0}, // 1
        {1, 0, 0, 0}, // 2
        {0, 1, 0, 0}, // 3
        {2, 0, 0, 0}, // 4
        {0, 0, 1, 0}, // 5
        {1, 1, 0, 0}, // 6
        {0, 0, 0, 1}, // 7
        {3, 0, 0, 0}, // 8
        {0, 2, 0, 0}  // 9
    };

    
    int dp23[47][30];

    void initDP() {
        for (int a = 0; a <= 46; a++) {
            for (int b = 0; b <= 29; b++) {

                int best = INT_MAX;

                
                for (int k = 0; k <= min(a, b); k++) {

                    int rem2 = a - k;
                    int rem3 = b - k;

                    int digitsFor2 = (rem2 + 2) / 3;
                    int digitsFor3 = (rem3 + 1) / 2;

                    best = min(
                        best,
                        k + digitsFor2 + digitsFor3
                    );
                }

                dp23[a][b] = best;
            }
        }
    }

    
    array<int, 4> factorize(long long t) {

        array<int, 4> need = {0, 0, 0, 0};

        int primes[4] = {2, 3, 5, 7};

        for (int i = 0; i < 4; i++) {

            while (t % primes[i] == 0) {
                need[i]++;
                t /= primes[i];
            }
        }

        if (t != 1) {
            return {-1, -1, -1, -1};
        }

        return need;
    }

    
    int minDigits(const array<int, 4>& need) {

        return dp23[need[0]][need[1]]
             + need[2]
             + need[3];
    }

    
    string build(int len, array<int, 4> need) {

        string ans;
        ans.reserve(len);

        for (int pos = 0; pos < len; pos++) {

            for (int digit = 1; digit <= 9; digit++) {

                array<int, 4> remaining = need;

                // Remove the factors supplied by this digit.
                for (int k = 0; k < 4; k++) {
                    remaining[k] =
                        max(0,
                            remaining[k] - factor[digit][k]);
                }

                int left = len - pos - 1;

                // Can the remaining digits supply everything?
                if (minDigits(remaining) <= left) {

                    ans.push_back(char('0' + digit));

                    need = remaining;

                    break;
                }
            }
        }

        return ans;
    }

    string smallestNumber(string num, long long t) {

        initDP();

        array<int, 4> need = factorize(t);

        // t contains a prime other than 2,3,5,7.
        if (need[0] == -1)
            return "-1";

        int n = num.size();

        
        int requiredLength = minDigits(need);

        
        if (requiredLength > n) {
            return build(requiredLength, need);
        }

        

        vector<array<int, 4>> prefix(n + 1);
        vector<bool> zeroPrefix(n + 1, false);

        prefix[0] = {0, 0, 0, 0};

        for (int i = 0; i < n; i++) {

            prefix[i + 1] = prefix[i];

            int digit = num[i] - '0';

            zeroPrefix[i + 1] =
                zeroPrefix[i] || (digit == 0);

            if (digit != 0) {

                for (int k = 0; k < 4; k++) {
                    prefix[i + 1][k] +=
                        factor[digit][k];
                }
            }
        }

        

        if (!zeroPrefix[n]) {

            bool valid = true;

            for (int k = 0; k < 4; k++) {

                if (prefix[n][k] < need[k]) {
                    valid = false;
                    break;
                }
            }

            if (valid)
                return num;
        }

        

        for (int i = n - 1; i >= 0; i--) {

            
            if (zeroPrefix[i])
                continue;

            int currentDigit = num[i] - '0';

            
            for (int newDigit = currentDigit + 1;
                 newDigit <= 9;
                 newDigit++) {

                array<int, 4> remaining = need;

                
                for (int k = 0; k < 4; k++) {

                    remaining[k] =
                        max(
                            0,
                            remaining[k] - prefix[i][k]
                        );
                }

                
                for (int k = 0; k < 4; k++) {

                    remaining[k] =
                        max(
                            0,
                            remaining[k] -
                            factor[newDigit][k]
                        );
                }

                int suffixLength = n - i - 1;

               
                if (minDigits(remaining) <= suffixLength) {

                    string answer;

                    // Original prefix.
                    answer += num.substr(0, i);

                    // Increased digit.
                    answer.push_back(
                        char('0' + newDigit)
                    );

                   
                    answer += build(
                        suffixLength,
                        remaining
                    );

                    return answer;
                }
            }
        }

    

        return build(n + 1, need);
    }
};