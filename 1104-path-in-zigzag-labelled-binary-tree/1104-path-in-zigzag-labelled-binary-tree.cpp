class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> path;

        while (label >= 1) {
            path.push_back(label);

            int level = log2(label);
            int start = 1 << level;
            int end = (1 << (level + 1)) - 1;

            label = (start + end - label) / 2;
        }

        reverse(path.begin(), path.end());
        return path;
    }
};