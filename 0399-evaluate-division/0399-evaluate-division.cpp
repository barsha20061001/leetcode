class Solution {
public:
    double dfs(const string& current,
               const string& target,
               unordered_map<string, vector<pair<string, double>>>& graph,
               unordered_set<string>& visited) {
        
        if (current == target) return 1.0;

        visited.insert(current);

        for (auto& [next, value] : graph[current]) {
            if (!visited.count(next)) {
                double result = dfs(next, target, graph, visited);

                if (result != -1.0) {
                    return value * result;
                }
            }
        }

        return -1.0;
    }

    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {
        
        unordered_map<string, vector<pair<string, double>>> graph;

        for (int i = 0; i < equations.size(); i++) {
            string a = equations[i][0];
            string b = equations[i][1];

            graph[a].push_back({b, values[i]});
            graph[b].push_back({a, 1.0 / values[i]});
        }

        vector<double> answer;

        for (auto& query : queries) {
            string source = query[0];
            string destination = query[1];

            if (!graph.count(source) || !graph.count(destination)) {
                answer.push_back(-1.0);
                continue;
            }

            unordered_set<string> visited;
            answer.push_back(
                dfs(source, destination, graph, visited)
            );
        }

        return answer;
    }
};