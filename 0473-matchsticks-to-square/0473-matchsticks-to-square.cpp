class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int total = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        // Calculates the total length of all matchsticks.

        if (total % 4 != 0)
       // A square has 4 equal sides.
 // If the total length isn't divisible by 4, forming a square is impossible. 
            return false;

        int side = total / 4; // Stores the required length of each side.
        sort(matchsticks.rbegin(), matchsticks.rend());

        if (matchsticks[0] > side)
        // If the longest stick is longer than one side of the square, the answer is immediately false.
            return false;

        vector<int> sides(4, 0); // Stores the current lengths of the four sides. 

        function<bool(int)> solve = [&](int index) {
            if (index == matchsticks.size())
                return sides[0] == side &&
                       sides[1] == side &&
                       sides[2] == side &&
                       sides[3] == side;

            for (int i = 0; i < 4; i++) {
                if (sides[i] + matchsticks[index] > side)
                // If adding this stick exceeds the target side length, skip this side.
                    continue;

                sides[i] += matchsticks[index];

                if (solve(index + 1))
                    return true;

                sides[i] -= matchsticks[index];

                if (sides[i] == 0)
                    break;
            }

            return false;
        };

        return solve(0);
    }
};    