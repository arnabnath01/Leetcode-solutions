class Solution {
    bool bfs(int node, vector<int>& vis, vector<vector<int>>& adj) {
        queue<pair<int, int>> q;
        q.push({node, -1});
        vis[node] = 1;
        while (!q.empty()) {
            int child = q.front().first;
            int parent = q.front().second;
            q.pop();

            for (auto it : adj[child]) {
                if (!vis[it]) {
                    q.push({it, child});
                    vis[it] = 1;
                } else if (parent != it) {
                    return true;
                }
            }
        }
        return false;
    }

    vector<vector<int>> convert(vector<vector<int>>& pre, int n) {
        vector<vector<int>> adj(n);
        for (auto& edge : pre) {
            int a = edge[0];
            int b = edge[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        return adj;
    }

public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj = convert(prerequisites, n);
        vector<int> vis(n, 0);
        
        // Debug output to print adjacency list
        for (int i = 0; i < n; i++) {
            for (auto x : adj[i]) {
                cout << i << " " << x << " ";
            }
            cout << endl;
        }

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                if (bfs(i, vis, adj)) return false; // Changed to false for "canFinish"
            }
        }
        return true; // Changed to true for "canFinish"
    }
};
