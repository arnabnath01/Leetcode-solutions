class Solution {
public:
    int findMin(vector<int>& nums) {
        int s=0,e=nums.size()-1;

        int mini = nums[s];

        while(s<=e)
        {
            int mid = s+(e-s)/2;
    // if left half is sorted 
            if(nums[s]<=nums[mid]){
                mini = min(mini , nums[s]);
                s=mid+1;
            }
            // if right half is sorted 
            else{
                 mini = min(mini , nums[mid]);
                 e=mid-1;
            }
        }
        return mini;
    }
};