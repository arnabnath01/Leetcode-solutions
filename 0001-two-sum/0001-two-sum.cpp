class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>>v;
        for(int i=0;i<nums.size();i++){
            v.push_back({nums[i],i});
        }
        sort(v.begin(),v.end());

        int n=v.size();
        int start=0,end=n-1;
        while(start<end){
            auto el1=v[start],el2=v[end];
            if(el1.first+el2.first==target){
                return {el1.second,el2.second};
            }
            else if(el1.first+el2.first>target){
                end--;
            }
            else start++;
        }
        return {0,0};
        
    }
};