class Solution {
public:
// SPACE OPTIMIZATION

    bool canPartition(vector<int>& nums) {
        
        int sum=0;
        for(auto x:nums) sum+=x;
        if(sum & 1) return false;
        int n = nums.size();
        //sum is even
        
        vector<bool> prev(sum/2+1,0),curr(sum/2+1,0);
        prev[0]=true,curr[0]=true;
        //base case 
        for(int i =0;i<n;i++) curr[0]=true;
        if(nums[0]<=sum/2)
        prev[nums[0]]=true;

        for(int ind=1;ind<n;ind++){
            for(int target=1;target<=sum/2;target++){
                int nonTake=prev[target];
                int take=false;
                if(nums[ind]<=target) take=prev[target-nums[ind]];
                curr[target]=take || nonTake;
            }
            prev=curr;
        }
        return prev[sum/2];
        // return subsetSumToK(n,sum/2,nums);
    }
};