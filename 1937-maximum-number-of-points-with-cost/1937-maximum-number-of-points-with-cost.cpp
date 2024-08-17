class Solution {
    using ll =long long;
public:
    long long maxPoints(vector<vector<int>>& points) {
        int n=points.size(),m=points[0].size();

        // vector<vector<ll>>dp(n,vector<ll>(m,0));
        
        // for(int i=0;i<m;i++){
        //     dp[0][i]=points[0][i];
        // }

        //  for(int i=1;i<n;i++){
        //     for(int j=0;j<m;j++){
                
        //         int maxi=dp[i-1][j];
        //         for(int k=0;k<m;k++){
        //             maxi=max(maxi,dp[i-1][j]-abs(k-j));
        //         }
        //         dp[i][j]=points[i][j]+maxi;   // max among the previous ones 
        //     }
            
        // }



        vector<int>curr(m,0),prev(m,0);

         for(int i=0;i<m;i++){
            prev[i]=points[0][i];
        }

         for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                
                int maxi=prev[j];
                for(int k=0;k<m;k++){
                    maxi=max(maxi,prev[k]-abs(k-j));
                }
                curr[j]=points[i][j]+maxi;   // max among the previous ones 
            }
            prev=curr;
        }


        return *max_element(prev.begin(),prev.end());
    }
};