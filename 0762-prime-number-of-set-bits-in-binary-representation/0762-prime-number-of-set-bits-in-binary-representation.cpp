class Solution {
public:
    int countPrimeSetBits(int left, int right) {  // Function takes range left to right and returns count.
        int ans = 0; 

        for (int i = left; i <= right; i++) {  // Checks every number from left to right.
            int bits = __builtin_popcount(i); // counts the number of 1s in binary.

            if (bits == 2 || bits == 3 || bits == 5 || bits == 7 ||  
                bits == 11 || bits == 13 || bits == 17 || bits == 19) 
                ans++;
        }

        return ans;
    }
};