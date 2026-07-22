class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();

        queue<pair<int, int>> q;
        q.push({entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]] = '+';

        int directions[4][2] = {
            {-1, 0},
            {1, 0},
            {0, -1},
            {0, 1}
        };

        int steps = 0;

        while (!q.empty()) {
            int size = q.size();
            steps++;

            while (size--) {
                auto [row, col] = q.front();
                q.pop();

                for (auto& direction : directions) {
                    int newRow = row + direction[0];
                    int newCol = col + direction[1];

                    if (newRow < 0 || newRow >= m ||
                        newCol < 0 || newCol >= n ||
                        maze[newRow][newCol] == '+') {
                        continue;
                    }

                    if (newRow == 0 || newRow == m - 1 ||
                        newCol == 0 || newCol == n - 1) {
                        return steps;
                    }

                    maze[newRow][newCol] = '+';
                    q.push({newRow, newCol});
                }
            }
        }

        return -1;
    }
};