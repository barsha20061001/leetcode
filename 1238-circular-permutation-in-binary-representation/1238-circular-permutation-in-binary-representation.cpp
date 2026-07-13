class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        vector<int> ans;

        for (int i = 0; i < (1 << n); i++) {
            int gray = i ^ (i >> 1);
            ans.push_back(gray ^ start);
        }

        // The normal Gray code sequence is:
        // gray(i) = i ^ (i >> 1)
      // It starts from 0, and every adjacent value differs by exactly one bit.
     /// To make the sequence start from start, XOR every Gray code value with start:
     // gray ^ start

        return ans;
    }
};