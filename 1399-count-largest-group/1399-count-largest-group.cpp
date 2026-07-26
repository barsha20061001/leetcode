class Solution {
public:
    int countLargestGroup(int n) {
        vector<int> groups(37, 0);

        for (int i = 1; i <= n; i++) {
            int x = i, sum = 0;

            while (x > 0) {
                sum += x % 10;
                x /= 10;
            }

            groups[sum]++;
        }

        int largest = *max_element(groups.begin(), groups.end());
        int count = 0;

        for (int size : groups)
            if (size == largest)
                count++;

        return count;
    }
};