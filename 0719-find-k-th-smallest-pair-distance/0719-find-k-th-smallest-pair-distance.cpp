class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());



        priority_queue<int,vector<int>,greater<int>>pq;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                pq.push(abs(nums[i]-nums[j]));
            }
        }

        
        --k;
        while(k--){
            pq.pop();
        }

        return pq.top();

    }
};