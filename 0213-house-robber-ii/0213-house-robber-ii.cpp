class Solution {
public:

    int rob(vector<int>& nums) {
        
        int n=nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[1],nums[0]);
        int prev=nums[0];
        int prev2=0;
        for(int i=1;i<n-1;i++ ){

            int take=nums[i]; if(i>1) take+=prev2;
            int non_take=0+prev;
            int curr = max(take,non_take);
            
            prev2=prev;
            prev=curr;
        }

        int maxi1=prev;

        int prev11=nums[1];
        int prev12=0;
        for(int i=2;i<n;i++ ){

            int take=nums[i]; 
            if(i>2) take+=prev12;
            int non_take=0+prev11;
            int curr = max(take,non_take);
            
            prev12=prev11;
            prev11=curr;
        }

        int maxi2=prev11;

return max(maxi1,maxi2);
    }
};