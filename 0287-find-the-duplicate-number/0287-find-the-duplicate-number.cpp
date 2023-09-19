class Solution {
public:
    int findDuplicate(vector<int>& nums) {
         ios_base::sync_with_stdio(false);
        cin.tie(NULL) ;
    sort(nums.begin(),nums.end());
    for(int i=1;i<nums.size();i++){
        if(nums[i-1]==nums[i])
        return nums[i-1];
    }
        return nums[0];
    }
};