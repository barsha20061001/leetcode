class Solution {
public:
    int minOperations(vector<int>& nums) {

        for (int i = 1; i < nums.size(); i++) {
            // Start checking from the second element.
            // We compare every element with the first one.
            if (nums[i] != nums[0])
            // If any element is different from the first element, then the array is not already equal.
                return 1;
                // Choose the entire array as the subarray.
        }

        return 0;
    }
};