class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int>st;
        for(auto x:nums){
            st.insert(x);
        }
        int idx=0;
        for(auto it:st)
        {
            nums[idx++]=it;
        }
        return st.size();

    }
};