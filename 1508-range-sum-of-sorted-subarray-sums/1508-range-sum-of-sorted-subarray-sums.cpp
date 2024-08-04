class Solution {
public:

    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int>subarray;
            int MOD=1e9+7;
        for(int i=0;i<n;i++){
            subarray.push_back(nums[i]);
            int el=nums[i];
            for(int j=i+1;j<n;j++){
                el+=nums[j];
                subarray.push_back(el);
            }
        }

        sort(subarray.begin(),subarray.end());
        int sum=0;

        for(int i=left-1;i<right;i++){
            sum+=subarray[i];
            sum=sum%MOD;
        }

        return sum%MOD;
    }
};