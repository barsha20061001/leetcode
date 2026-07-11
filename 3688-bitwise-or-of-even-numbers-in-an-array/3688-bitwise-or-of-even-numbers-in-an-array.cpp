class Solution {
public:
    int evenNumberBitwiseORs(vector<int>& nums) {
        int ans = 0;

        for (int x : nums) {
            if ((x & 1) == 0) { // Checks whether the number is even.
                ans |= x;  // This is shorthand for ans = ans | x; It updates the cumulative bitwise OR.
            }
        }

        return ans;
    }
};