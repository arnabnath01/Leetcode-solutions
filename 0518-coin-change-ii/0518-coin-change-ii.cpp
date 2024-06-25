class Solution {
public:
int mod = 1e9+7;
    int change(int target, vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, 0));


        for(int j=0;j<=target;j++){
            dp[0][j]= j%nums[0]==0;
        }

        // Fill the rest of the DP table
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= target; j++) {
                int notTake = dp[i - 1][j];
                int take = 0;
                if (nums[i] <= j) {
                    take =  + dp[i][j - nums[i]];
                }
                dp[i][j] = (notTake+ take)%mod;
            }
        }

        // Debug output
        cout << "dp matrix is\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= target; j++) {
                if (dp[i][j] == INT_MAX) {
                    cout << "INF ";
                } else {
                    cout << dp[i][j] << " ";
                }
            }
            cout << endl;
        }
        cout << endl;


        // Final answer
       return  dp[n - 1][target];
    }
};