class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        vector<pair<int, int>> adj[n];
        for (auto it:flights) {
            adj[it[0]].push_back({it[1], it[2]});
        }
        vector<int> dist(n, INT_MAX);
        // stops,node,dist
        queue<pair<int, pair<int, int>>> q;

        q.push({0, {src, 0}});
        dist[src] = 0;
        // O(E) which is equal to flight.size()
        while (!q.empty()) {
            int stops = q.front().first;
            int node = q.front().second.first;
            int cost = q.front().second.second;
            q.pop();
            if (stops > k)
                continue; // no need to traverse new nodes, finish the remaining
                          // in the queue
            for (auto it : adj[node]) {
                int adjNode = it.first;
                int nodeWt = it.second;

                if (cost + nodeWt < dist[adjNode] ) {
                    dist[adjNode] = cost + nodeWt;
                    q.push({stops + 1, {adjNode, cost + nodeWt}});
                }
            }
        }

        if (dist[dst] == INT_MAX)
            return -1;
        return dist[dst];
    }
};