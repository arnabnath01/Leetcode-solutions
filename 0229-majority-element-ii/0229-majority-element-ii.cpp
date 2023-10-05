class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
       
        unordered_map<int ,int > mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        vector<int> ans;
        
        for(auto x: mp)
        {
            if(x.second>(nums.size()/3))
                 ans.push_back(x.first);
        }
        return ans;
    }


//  unordered_map<int,int>mp;
//         int i;
//         for(i=0;i<nums.size();i++)
//         mp[nums[i]]++;
//         vector<int>ans;
//         for(auto x:mp)
//         {
//             if(x.second>(nums.size()/3))
//             ans.push_back(x.first);
//         }
//         return ans;




};