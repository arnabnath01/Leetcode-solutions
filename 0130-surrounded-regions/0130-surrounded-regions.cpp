class Solution {
private:
    void dfs(int x, int y, int drow[], int dcol[], vector<vector<char>>& board,
             vector<vector<int>>& vis) {
        int n = board.size();
        int m = board[0].size();

        vis[x][y] = 1;
        for (int i = 0; i < 4; i++) {
            int nrow = x + drow[i];
            int ncol = y + dcol[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                board[nrow][ncol] == 'O' && !vis[nrow][ncol]) {
                dfs(nrow, ncol, drow, dcol, board, vis);
            }
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        int drow[4] = {-1, 0, 1, 0};
        int dcol[4] = {0, 1, 0, -1};

        // Check first and last row
        for (int j = 0; j < m; j++) {
            if (board[0][j] == 'O' && !vis[0][j]) {
                dfs(0, j, drow, dcol, board, vis);
            }
            if (board[n - 1][j] == 'O' && !vis[n - 1][j]) {
                dfs(n - 1, j, drow, dcol, board, vis);
            }
        }

        // Check first and last column
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O' && !vis[i][0]) {
                dfs(i, 0, drow, dcol, board, vis);
            }
            if (board[i][m - 1] == 'O' && !vis[i][m - 1]) {
                dfs(i, m - 1, drow, dcol, board, vis);
            }
        }

        // Convert unvisited 'O's to 'X's
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }
};