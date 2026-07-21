class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        int left = 0, right = n - 1;

        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       greater<pair<int, int>>> pq;

        for (int i = 0; i < candidates && left <= right; i++) {
            pq.push({costs[left], left});
            left++;
        }

        for (int i = 0; i < candidates && left <= right; i++) {
            pq.push({costs[right], right});
            right--;
        }

        long long total = 0;

        while (k--) {
            auto [cost, index] = pq.top();
            pq.pop();

            total += cost;

            if (left <= right) {
                if (index < left) {
                    pq.push({costs[left], left});
                    left++;
                } else {
                    pq.push({costs[right], right});
                    right--;
                }
            }
        }

        return total;
    }
};