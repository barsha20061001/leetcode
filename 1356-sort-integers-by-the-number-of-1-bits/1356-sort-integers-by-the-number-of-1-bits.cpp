class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {

        sort(arr.begin(), arr.end(), [](int a, int b) { 
            // sort() compares two numbers a and b repeatedly.
            // The [] starts a lambda function (an anonymous comparator).

            int bitsA = __builtin_popcount(a); // Count the number of 1s in a.
            int bitsB = __builtin_popcount(b);

            if (bitsA == bitsB)  // If both numbers have the same number of set bits...
                return a < b;  // If set bits are equal, place the smaller number first.

            return bitsA < bitsB; // Otherwise, the number with fewer set bits comes first.
        });

        return arr;
    }
};