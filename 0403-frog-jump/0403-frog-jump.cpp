class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int,unordered_set<int>> dp;
        dp[1]={1};

        for(int i=1;i<stones.size();++i){
            for(auto jump: dp[stones[i]])
            {
                dp[stones[i]+jump].insert(jump);
                dp[stones[i]+jump-1].insert(jump-1);
                dp[stones[i]+jump+1].insert(jump+1);
            }
        }

        return dp[stones.back()].size() != 0;
    }
};