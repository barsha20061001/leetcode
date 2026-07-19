class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int count = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int currentGCD = 0;

            for (int j = i; j < n; j++) {
                currentGCD = gcd(currentGCD, nums[j]);

                if (currentGCD == k)
                    count++;

                // Future GCDs will always divide currentGCD,
                // so they can never become k.
                if (currentGCD % k != 0)
                    break;
            }
        }

        return count;
    }
};