class Solution {
public:
    bool isIncreasing(vector<int>& nums){
        for(int i=1;i<nums.size()-1;i++){
            if(nums[i-1]<=nums[i] && nums[i]<=nums[i+1])  continue;
            else return false;
        }

        return true;
    }

    bool isDecreasing(vector<int>& nums){
        for(int i=1;i<nums.size()-1;i++){
            if(nums[i-1]>=nums[i] && nums[i]>=nums[i+1])  continue;
            else return false;
        }
        return true;
    }
    bool isMonotonic(vector<int>& nums) {

        if(isIncreasing(nums) || isDecreasing(nums))
        return true;
        return false;
    }
};