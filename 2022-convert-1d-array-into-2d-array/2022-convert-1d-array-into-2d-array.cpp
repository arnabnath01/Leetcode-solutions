class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& arr, int m, int n) {
        vector<vector<int>> ans;

        if(arr.size()<=2 ||  arr.size()!=m*n) return ans;
        ans.resize(m,vector<int>(n));
        int j=0;
        for(int i=0;i<m;i++){
            vector<int>temp;
            for(int k=0;k<n;k++){
                temp.push_back(arr[j++]);
            }
            ans[i]=temp;
        }
        return ans;
    }
};