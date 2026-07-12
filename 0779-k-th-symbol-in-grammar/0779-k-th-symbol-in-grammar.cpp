class Solution {
public:
    int kthGrammar(int n, int k) {
        if (n == 1)
            return 0;
            // The first row is Row 1 : 0 So regardless of k, return 0.

        int parent = kthGrammar(n - 1, (k + 1) / 2);
        // Every symbol in row n comes from one symbol in row n−1.

        if (k % 2 == 1) 
        // If k is odd, it is the left child.
            return parent;

        return 1 - parent;
        // Otherwise, k is even, meaning it is the right child.
         // Right child is always the opposite of its parent.
    }
};