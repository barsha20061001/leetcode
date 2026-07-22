class Solution {
public:
    int minimumArrayLength(vector<int>& nums) {
        int mn = *min_element(nums.begin(), nums.end());
        int countMin = 0;

        for (int x : nums) {
            if (x % mn != 0) {
                return 1;
            }

            if (x == mn) {
                countMin++;
            }
        }

        return (countMin + 1) / 2;
    }
};