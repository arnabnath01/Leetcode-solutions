class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        priority_queue<pair<int,string>>p;
        int n=names.size();
        for(int i=0;i<n;i++){
            p.push({heights[i],names[i]});
        }

        vector<string>ans;
        while(!p.empty()){
            auto it=p.top();
            p.pop();
            ans.push_back(it.second);
        }

        return ans;
    }
};