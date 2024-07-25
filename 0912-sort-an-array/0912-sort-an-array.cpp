class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int>pq;
        for(auto x:nums){
            pq.push(x);

        }
        int n=nums.size();
        int i=n-1;
        while(!pq.empty()){
            nums[i--]=pq.top();
            pq.pop();
        }
        return nums;
    }
};