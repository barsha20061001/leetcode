
//The Hamming Distance is simply the number of bit positions where two numbers differ.
//The trick is:
//XOR the two numbers.
//Count the number of set bits (1s).


class Solution {
public:
    int hammingDistance(int x, int y) {
        return __builtin_popcount(x ^ y);
    }
};