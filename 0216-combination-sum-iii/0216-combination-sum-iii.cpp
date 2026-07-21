class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> current;

        function<void(int, int)> backtrack = [&](int start, int remaining) {
            if (current.size() == k) {
                if (remaining == 0)
                    ans.push_back(current);
                return;
            }

            for (int num = start; num <= 9; num++) {
                if (num > remaining)
                    break;

                current.push_back(num);
                backtrack(num + 1, remaining - num);
                current.pop_back();
            }
        };

        backtrack(1, n);
        return ans;
    }
};