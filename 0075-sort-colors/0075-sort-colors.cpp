class Solution {
public:
    void sortColors(vector<int>& nums) {
        int right=nums.size()-1;
        int left=0,mid=0;
        while(mid<=right){
            if(nums[mid]==2){
                swap(nums[mid],nums[right]);
            
                right--;
            }
            else if(nums[mid]==0)
            { 
                swap(nums[mid],nums[left]);
                mid++;
                left++;
            }else{
               
                mid++;

            }
        }
    }
};