class Solution {
public:
    bool isPrime(int num) {
        if (num < 2)
            return false;

        if (num % 2 == 0)
            return num == 2;

        for (int i = 3; 1LL * i * i <= num; i += 2) {
            if (num % i == 0)
                return false;
        }

        return true;
    }

    int primePalindrome(int n) {
        if (n <= 2) return 2;
        if (n <= 3) return 3;
        if (n <= 5) return 5;
        if (n <= 7) return 7;
        if (n <= 11) return 11;

        for (int root = 1; root < 100000; root++) {
            string firstHalf = to_string(root);
            string palindrome = firstHalf;

            for (int i = firstHalf.size() - 2; i >= 0; i--)
                palindrome += firstHalf[i];

            int value = stoi(palindrome);

            if (value >= n && isPrime(value))
                return value;
        }

        return -1;
    }
};