class Solution {
public:
      int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int count = n - i; // Number of elements >= nums[i]
            if (nums[i] >= count) {
                // Check if it's exactly `count` elements
                if (i == 0 || nums[i - 1] < count) {
                    return count;
                }
            }
        }

        return -1;
    }
};