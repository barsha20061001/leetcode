class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {

        vector<int> arr; // Creates the answer array.

        arr.push_back(first); // The first element is already given.

        for (int i = 0; i < encoded.size(); i++) { // Go through every encoded value.
            arr.push_back(arr[i] ^ encoded[i]); // Use the formula
        }

        return arr;
    }
};