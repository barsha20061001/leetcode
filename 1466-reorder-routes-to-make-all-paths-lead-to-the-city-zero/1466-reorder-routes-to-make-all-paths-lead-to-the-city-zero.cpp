class Solution {
public:
    int dfs(int node, int parent, vector<vector<pair<int, int>>>& graph) {
        int changes = 0;

        for (auto& [next, needsChange] : graph[node]) {
            if (next == parent) continue;

            changes += needsChange;
            changes += dfs(next, node, graph);
        }

        return changes;
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> graph(n);

        for (auto& edge : connections) {
            int u = edge[0], v = edge[1];

            graph[u].push_back({v, 1}); // original direction: needs reversal
            graph[v].push_back({u, 0}); // reverse direction: already correct
        }

        return dfs(0, -1, graph);
    }
};