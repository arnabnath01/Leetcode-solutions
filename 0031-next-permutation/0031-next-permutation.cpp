class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int ind=-1;
        int n=nums.size();

        // finding the breakpoint
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                ind=i;
                break;
            }
        }

        // this states that the eleemmnt is the largest, so go back to the first one
        if(ind==-1){
            reverse(nums.begin(),nums.end());
            return ;
        }

        // find someone greater,but not the largest
        for(int i=n-1;i>ind;i--){
            if(nums[ind]<nums[i]){
                swap(nums[ind],nums[i]);
                break;
            }
        }

        reverse(nums.begin()+ind+1,nums.end());

    }
};