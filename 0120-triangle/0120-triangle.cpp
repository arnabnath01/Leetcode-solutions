
// MEMOIZTION
class Solution {
public:

    // Tabulation ( opposite flow of memoization)
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,0));

        // filling the ground row
        for(int j=0;j<n;j++){
            dp[n-1][j]=triangle[n-1][j];
        }
    
        for(int i=n-2;i>=0;i--)
        {
            for(int j=i;j>=0;j--)
            {
                // if(i==n-1) return triangle[i][j];

                int down= triangle[i][j]+dp[i+1][j];
                int dr= triangle[i][j]+dp[i+1][j+1]; 
                dp[i][j]= min(down,dr);
            }
        }


        return dp[0][0];
    }
};