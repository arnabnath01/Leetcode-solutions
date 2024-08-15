class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int sum =0;
        int MOD=1e9+7;
        int n=arr.size();
        for(int i=0;i<n;i++){
            int mini=arr[i];
            // sum+=mini;
            for(int j=i;j<n;j++){
                mini=min(mini,arr[j]);
                sum=(sum+mini)%MOD;
            }
        }
        return sum;
    }
};