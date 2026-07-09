//The approach is:
//Reverse every row.
//Invert every element (0 → 1, 1 → 0).
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) { 
        // Function takes a 2D binary matrix and returns the modified matrix.

        for (auto &row : image) { // Visit every row of the matrix.

            reverse(row.begin(), row.end()); // Reverse the row.

            for (int &x : row) {  // Visit every element of the current row.
                x ^= 1; // Flip the bit using XOR.
            }
        }

        return image; // Return the modified matrix.
    }
};