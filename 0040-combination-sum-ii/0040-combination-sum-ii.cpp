class Solution {
   
  
public:

 void combsum(int ind,int target,vector<vector<int>>&ans,vector<int>& candidates,vector<int>&ds){
            
                if(target==0){
                ans.push_back(ds);
                return ;
                }

           for(int i=ind;i<candidates.size();i++)
            {
                if(i>ind && candidates[i]==candidates[i-1]) continue;
                if(candidates[i]>target) break;
                ds.push_back(candidates[i]);
                combsum(i+1,target-candidates[i],ans,candidates,ds);
                ds.pop_back();
            }
        }


    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
     sort(candidates.begin(), candidates.end());
        vector<vector<int>>ans;
        vector<int>ds;
        combsum(0,target,ans,candidates,ds);

        return ans;
        
    }











};