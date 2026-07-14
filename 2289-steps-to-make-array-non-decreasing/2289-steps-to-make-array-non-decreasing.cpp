class Solution {
public:
    int totalSteps(vector<int>& nums) {
        // {value, steps needed before this value gets removed}
        vector<pair<int, int>> st;
        int answer = 0;

        for (int x : nums) {
            int steps = 0;

            while (!st.empty() && x >= st.back().first) {
                steps = max(steps, st.back().second);
                st.pop_back();
            }

            if (st.empty()) {
                steps = 0;
            } else {
                steps++;
            }

            answer = max(answer, steps);
            st.push_back({x, steps});
        }

        return answer;
    }
};