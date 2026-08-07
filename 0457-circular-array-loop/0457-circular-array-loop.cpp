class Solution {
public:
    int nextIndex(vector<int>& nums, int i) {
        int n = nums.size();
        return ((i + nums[i]) % n + n) % n;
    }
    bool circularArrayLoop(vector<int>& nums) {

        int n = nums.size();

        for (int i = 0; i < n; i++) {

            // Try starting from i
            bool forward = nums[i] > 0;

            int slow = i;
            int fast = i;

            while (true) {

                // Move slow one step
                int nextSlow = nextIndex(nums, slow);

                // Direction must remain the same
                if ((nums[nextSlow] > 0) != forward)
                    break;

                slow = nextSlow;

                // Move fast one step
                int nextFast = nextIndex(nums, fast);

                if ((nums[nextFast] > 0) != forward)
                    break;

                // Move fast second step
                int nextFast2 = nextIndex(nums, nextFast);

                if ((nums[nextFast2] > 0) != forward)
                    break;

                fast = nextFast2;

                // We found a cycle
                if (slow == fast) {

                    // Cycle of length 1 is not allowed
                    if (slow == nextIndex(nums, slow))
                        break;

                    return true;
                }
            }
        }

        return false;
    }
};