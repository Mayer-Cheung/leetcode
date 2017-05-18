class Solution {
public:
    int countComponents(int n, vector<pair<int, int>>& edges) {
        vector<vector<int>> g(n);
        vector<bool> visited(n);
        for (int i = 0; i < n; i++)
            visited[i] = false;
        int cnt = 0;
        for (auto e : edges) {
            g[e.first].push_back(e.second);
            g[e.second].push_back(e.first);
        }
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, g, visited);
                cnt++;
            }
        }
        return cnt;
    }
    void dfs(int s, vector<vector<int>>& g, vector<bool>& visited) {
        if (visited[s])
            return;
        visited[s] = true;
        for (int i = 0; i < g[s].size(); i++)
            if (!visited[g[s][i]]) {
                dfs(g[s][i], g, visited);
            }
    }
};
