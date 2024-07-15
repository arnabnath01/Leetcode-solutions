class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {

        int n = heights.size();
        int m = heights[0].size();

        if (n == 1 && m == 1) {
            return 0;
        }
        // O(N2)
        vector<vector<int>> vis(n, vector<int>(m, INT_MAX));

        int dx[] = {-1, 0, 0, 1};
        int dy[] = {0, 1, -1, 0};

        // if(grid[0][0]) return -1;
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            q;

        q.push({0, {0, 0}});
        vis[0][0] = 0;

        // O(N2)
        while (!q.empty()) {
            int diff = q.top().first;
            int x = q.top().second.first;
            int y = q.top().second.second;
            q.pop();
            if (x == n - 1 && y == m - 1)
                        return diff;
            for (int i = 0; i < 4; i++) {

                int newi = x + dx[i];
                int newj = y + dy[i];
                
                if (newi < n && newi >= 0 && newj >= 0 && newj < m )
                     {
                    int efforts = max((abs(heights[newi][newj] - heights[x][y])),diff);

                    if(efforts<vis[newi][newj])
                    {
                        vis[newi][newj]=efforts;
                        q.push({efforts, {newi, newj}});
                    }
                    
                }
            }
        }

        return 0;
    }
};