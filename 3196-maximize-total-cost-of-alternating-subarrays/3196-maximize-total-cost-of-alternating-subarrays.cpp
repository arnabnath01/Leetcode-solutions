class Solution {
    using ll = long long;
public:
    long long maximumTotalCost(vector<int>& nums) {
        int n = nums.size();
        vector<vector<ll>> dp(n + 1, vector<ll>(2, 0));
        for (ll ind = n - 1; ind >= 0; ind--) {
            for (ll flag = 1; flag >= 0; flag--) {
                ll old = 0;
                if (flag) {
                    old = nums[ind] + dp[ind + 1][0];
                } else {
                    old = abs(nums[ind]) + dp[ind + 1][1];
                }
                ll new_val = nums[ind] + dp[ind + 1][0];
                dp[ind][flag] = max(old, new_val);
            }
        }
        return dp[0][1];
    }
};