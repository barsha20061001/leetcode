class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<pair<int, int>> pairs;

        for (int i = 0; i < n; i++) {
            pairs.push_back({nums2[i], nums1[i]});
        }

        sort(pairs.rbegin(), pairs.rend());

        priority_queue<int, vector<int>, greater<int>> minHeap;
        long long sum = 0;
        long long answer = 0;

        for (auto &[value2, value1] : pairs) {
            sum += value1;
            minHeap.push(value1);

            if (minHeap.size() > k) {
                sum -= minHeap.top();
                minHeap.pop();
            }

            if (minHeap.size() == k) {
                answer = max(answer, sum * value2);
            }
        }

        return answer;
    }
};