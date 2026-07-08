class Solution {
public:
    int singleNumber(vector<int>& nums) {  // use XOR. As in this duplicate numbers cancel each other.
        int ans = 0;

        for (int x : nums) {
            ans = ans ^ x; //   a ^ a = 0 , a ^ 0 = a
        }

        // eg : nums = [4,1,2,1,2]  ;  =  4 ^ (1 ^ 1) ^ (2 ^ 2)  = 4 ^ 0 ^ 0 = 4

        return ans;
    }
};