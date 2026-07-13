class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> answer;
        // Stores all unique OR values found so far.
        unordered_set<int> previous;
        // Stores the OR values of all subarrays ending at the previous index.

        for (int num : arr) {
            unordered_set<int> current;

            current.insert(num);
            // Every element alone is a subarray.

            for (int value : previous)
            // Take every OR value of subarrays ending at the previous index.
                current.insert(value | num);
                // Extend each previous subarray by including the current number.

            for (int value : current)
                answer.insert(value);

            previous = current;
        }

        return answer.size();
    }
};