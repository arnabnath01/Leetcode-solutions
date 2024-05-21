class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int sbst = 1<<n;
        vector<vector<int>> ans;

        for(int i=0;i<sbst;i++)
        {
            vector<int> temp;
            for(int num=0;num<n;num++)
            {
                if (i & (1<<num)) temp.push_back(nums[num]);
            }
            ans.push_back(temp);
        }

        return ans;
    }
};