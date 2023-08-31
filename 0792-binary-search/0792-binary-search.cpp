class Solution {
public:
    int search(vector<int>& nums, int x) {
        int l=0;
        int r=nums.size()-1;
        while (l <= r) {
        int m = l + (r - l) / 2;
 
        if (nums[m] == x)
            return m;
 
        if (nums[m] < x)
            l = m + 1;
 
        else
            r = m - 1;
    }
     return -1;
    }
};