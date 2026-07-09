class Solution {
public:
    int xorOperation(int n, int start) {
        int ans = 0; 

        for (int i = 0; i < n; i++) { // Runs from 0 to n-1.
            int num = start + 2 * i; // Creates each array element.
            ans = ans ^ num; // XOR current number into answer.
        }

        return ans;
    }
};