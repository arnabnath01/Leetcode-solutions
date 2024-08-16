class Solution {
    int MOD = 1e9+7;
    int helper(int ind, int prev1, int prev2, int n, vector<int>& nums, int (&dp)[2001][52][52]) {
        if (ind == n) return 1;
        if (dp[ind][prev1][prev2] != -1) return dp[ind][prev1][prev2];
        int ans = 0;
        for (int i = prev1; i <= nums[ind]; i++) {
            int x1 = i;
            int x2 = nums[ind] - i;
            if (x1 >= prev1 && x2 <= prev2) {
                ans = (ans + helper(ind + 1, x1, x2, n, nums, dp)) % MOD;
            }
        }
        return dp[ind][prev1][prev2] = ans;
    }
public:
    int countOfPairs(vector<int>& nums) {
        int n = nums.size();
        int dp[2001][52][52];
        memset(dp, -1, sizeof(dp));
        return helper(0, 0, 50, n, nums, dp);
    }
};