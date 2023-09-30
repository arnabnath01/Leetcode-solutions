
// MEMOIZTION
class Solution {
public:

    int f(int i,int j,vector<vector<int>>& triangle,vector<vector<int>>& dp,int n)
    {
        if(i==n-1) return triangle[i][j]; // whenever it reaches bottom, loop ends
        if(dp[i][j]!=-1) return dp[i][j];
        int down= triangle[i][j]+f(i+1,j,triangle,dp,n);
        int dr= triangle[i][j]+f(i+1,j+1,triangle,dp,n);
        return dp[i][j]= min(down,dr);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return f(0,0,triangle,dp,n);
    }
};