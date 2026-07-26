class Solution {
public:
    int rotatedDigits(int n) {
        int count = 0;

        for (int x = 1; x <= n; x++) {
            int num = x;
            bool changed = false;
            bool valid = true;

            while (num > 0) {
                int digit = num % 10;

                if (digit == 3 || digit == 4 || digit == 7) {
                    valid = false;
                    break;
                }

                if (digit == 2 || digit == 5 || digit == 6 || digit == 9)
                    changed = true;

                num /= 10;
            }

            if (valid && changed)
                count++;
        }

        return count;
    }
};