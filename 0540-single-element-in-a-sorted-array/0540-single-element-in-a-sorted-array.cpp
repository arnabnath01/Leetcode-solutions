class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int n=nums.size();

        if(nums[0]!=nums[1]) return nums[0];
        if(nums[n-1]!=nums[n-2]) return nums[n-1];
        int s=1,e=n-2;

        while(s<=e)
        {
            int mid =(e+s)/2;

            if(nums[mid]!=nums[mid+1] && nums[mid]!=nums[mid-1]) 
            return nums[mid];

            // left side
            if((mid%2==1 && nums[mid]==nums[mid-1]) || (mid%2==0 && nums[mid]==nums[mid+1]))
            {
               s=mid+1; 
            }
            
            else e=mid-1;
        }

        return -1;

    }
};