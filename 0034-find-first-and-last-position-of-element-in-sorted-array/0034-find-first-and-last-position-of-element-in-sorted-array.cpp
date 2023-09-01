class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty()) return {-1,-1};
    if(!binary_search(nums.begin(),nums.end(),target)) return {-1,-1};


        int left = lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        int right = upper_bound(nums.begin(),nums.end(),target)-nums.begin();
    cout<<left <<" "<<right;
return {left,right-1};
    }
};