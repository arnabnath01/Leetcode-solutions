class Solution {
public:

    string shortestCommonSupersequence(string s1, string s2) {
        int n=s1.size(),m=s2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
	int lcsLen=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			// taking the string 
			if(s1[i-1]==s2[j-1])
				dp[i][j]= 1+ dp[i-1][j-1];

				// not taking the strign 
			else {
				dp[i][j]=0+max(dp[i-1][j],dp[i][j-1]);
				
				}
		}
	}

	string ans="";
	
		int i=n,j=m;
		while(i>0 && j>0)
		{
			if(s1[i-1]==s2[j-1])	// if char matches
			{
				ans+=s1[i-1];
                
				i--,j--;
			}
			else if(dp[i-1][j]>dp[i][j-1])
			{
                ans+=s1[i-1];
                i--;
            }	
			else{
                ans+=s2[j-1];
				j--;
                }
		}

        while(i>0)
        {
            ans+=s1[i-1];
            i--;
        }
         while(j>0)
        {
            ans+=s2[j-1];
            j--;
        }

	reverse(ans.begin(),ans.end());
	return ans; 
    }
};