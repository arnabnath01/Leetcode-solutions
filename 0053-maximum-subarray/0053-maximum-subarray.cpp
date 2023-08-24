

//O(N2) solution

// class Solution {
// public:
//     bool ifNeg(vector<int> nums)
//     {
//         for(auto i:nums)
//         {
//             if(i>=0 ) return false;
//         }
//         return true;
//     }
//     bool ifPos(vector<int> nums)
//     {
//         for(auto i:nums)
//         {
//             if(i<0 ) return false;
//         }
//         return true;
//     }
//     int maxSubArray(vector<int>& nums) {
       
//        if(ifNeg(nums))
//        return *max_element(nums.begin(), nums.end());

//        if(ifPos(nums))
//        {
//            int sum=0;
//            for(auto i:nums)
//            sum+=i;
//            return sum;
//        }
//     int maxSum=0,curSum=0;
//     for(int i=0;i<nums.size();i++)
//     {
        

//         curSum+=nums[i];
//         if(curSum>maxSum)
//         maxSum=curSum;
//         if(curSum<0)
//         curSum=0;

//     }
//     return maxSum;
//     }
// };


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curMax = 0, maxTillNow = INT_MIN;
        for(auto c : nums)
            curMax = max(c, curMax + c),
            maxTillNow = max(maxTillNow, curMax);
        return maxTillNow;
    }
};