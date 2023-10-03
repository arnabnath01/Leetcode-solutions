class Solution {
public:
// TABULATION

    bool canPartition(vector<int>& nums) {
        
        int sum=0;
        for(auto x:nums) sum+=x;
        if(sum & 1) return false;
        int n = nums.size();
        //sum is even
        
        vector<vector<bool>> dp(n,vector<bool>(sum/2+1,0));
        //base case 
        for(int i =0;i<n;i++) dp[i][0]=true;
        if(nums[0]<=sum/2)
        dp[0][nums[0]]=true;

        for(int ind=1;ind<n;ind++){
            for(int target=1;target<=sum/2;target++){
                int nonTake=dp[ind-1][target];
                int take=false;
                if(nums[ind]<=target) take=dp[ind-1][target-nums[ind]];
                dp[ind][target]=take || nonTake;
            }
        }
        return dp[n-1][sum/2];

        // return subsetSumToK(n,sum/2,nums);
    }
};