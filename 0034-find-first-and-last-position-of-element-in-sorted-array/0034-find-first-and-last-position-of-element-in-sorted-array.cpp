class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) {
            return {-1, -1};
        }
        
        int fst = -1, lst = -1;
        int s = 0, e = nums.size() - 1;
        
        while (s <= e) {
            int m = s + (e - s) / 2;
            if (nums[m] == target) {
                fst = m;
                e = m - 1;
            } else if (nums[m] > target) {
                e = m - 1;
            } else {
                s = m + 1;
            }
        }
        
        s = 0, e = nums.size() - 1;
        
        while (s <= e) {
            int m = s + (e - s) / 2;
            if (nums[m] == target) {
                lst = m;
                s = m + 1;
            } else if (nums[m] > target) {
                e = m - 1;
            } else {
                s = m + 1;
            }
        }
        
        if (fst == -1 || lst == -1) {
            return {-1, -1};
        } else {
            return {fst, lst};
        }
    }
};