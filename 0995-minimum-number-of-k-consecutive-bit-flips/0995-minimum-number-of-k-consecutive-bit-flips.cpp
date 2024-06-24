class Solution {
public:
// O(n) time complexity 
// O(n) space complexity 
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        int times = 0, ans = 0;
        vector<int> flipped(n, 0);

        for (int i = 0; i < n; i++) {

            // setting the first limit
            if (i >= k)
                times -= flipped[i - k];

            if ((times % 2 == 0 && nums[i] == 0) ||
                (times % 2 == 1 && nums[i] == 1)) {
                // setting the last limit
                if (i + k > n)
                    return -1;
                times++;
                ans++, flipped[i] = 1;
            }
        }

        return ans;
    }
};