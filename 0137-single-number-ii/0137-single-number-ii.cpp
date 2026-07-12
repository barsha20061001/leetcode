class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0; // ones stores bits that have appeared once so far.

        for (int num : nums) {
            ones = (ones ^ num) & ~twos;
            twos = (twos ^ num) & ~ones;
        }
        // ones ^ num toggles the bits of num in ones.
   /// ~twos gives bits that are not currently in twos.
     // & ~twos prevents a bit from being present in both ones and twos.

        return ones;
    }
};