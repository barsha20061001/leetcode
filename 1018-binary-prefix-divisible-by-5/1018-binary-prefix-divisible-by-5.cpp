class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> ans;
        int num = 0; // Stores current prefix value modulo 5.

        for (int bit : nums) {  // Loop through each binary digit.
            num = (num * 2 + bit) % 5;  //  % 5 To keep the number small.

            if (num == 0)
                ans.push_back(true);
            else
                ans.push_back(false);
        }

        return ans;
    }
};