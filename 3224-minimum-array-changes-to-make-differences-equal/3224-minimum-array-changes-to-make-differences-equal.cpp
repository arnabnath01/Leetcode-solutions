class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        vector<int>freq(k+1,0);
        vector<int>v;
        int n=nums.size();
        for(int i=0;i<n/2;i++){
            int diff=abs(nums[i]-nums[n-i-1]);
            freq[diff]++;

            int a=nums[i] , b=nums[n-i-1];
            int thresold=max(max(a,b),k-min(a,b));
            v.push_back(thresold);  
        }

        sort(v.begin(),v.end());
        int ans=n/2;
        n/=2;
        for(int i=0;i<k+1;i++){
            int rest = n-freq[i];
            int greater=lower_bound(v.begin(),v.end(),i)-v.begin();
            ans=min(ans,rest+greater);
        }
        return ans;

    }
};