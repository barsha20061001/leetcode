class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        map<vector<int>, int> rowCount;

        for (const auto& row : grid) {
            rowCount[row]++;
        }

        int answer = 0;

        for (int col = 0; col < n; col++) {
            vector<int> column;

            for (int row = 0; row < n; row++) {
                column.push_back(grid[row][col]);
            }

            answer += rowCount[column];
        }

        return answer;
    }
};