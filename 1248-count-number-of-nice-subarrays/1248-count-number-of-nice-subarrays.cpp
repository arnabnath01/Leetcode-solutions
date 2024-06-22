class Solution {
    void trim(vector<int>& nums, int k)
    {
        for(auto &x:nums)
        {
            x=x%2;    
        }
    }

    int f(vector<int>& nums, int k) {
           trim(nums,k);
        int i=0,j=0,cnt=0,ans=0;
        
        while(j<nums.size())
        {

            cnt+=nums[j];

            while(cnt>k)
            {
                cnt-=nums[i++];
            }

          
            ans+=j-i+1;

            j++;
        }

        return ans;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        cout.tie(0),cin.tie(0),ios_base::sync_with_stdio(0);
        return f(nums,k)-f(nums,k-1);
 
    }
};