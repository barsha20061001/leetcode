class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> prefix(arr.size() + 1, 0);
        vector<int> answer;

        for (int i = 0; i < arr.size(); i++) {
            prefix[i + 1] = prefix[i] ^ arr[i];
        }

        for (auto& query : queries) {
            int left = query[0];
            int right = query[1];

            answer.push_back(prefix[right + 1] ^ prefix[left]);
        }

        return answer;
    }
};