// class Solution {
// public:
//     bool isInterleave(string s1, string s2, string s3) {
//         if(s3==""){
//          if(s1!="" && s2!="") return false;   
//         } 

   
//     reverse(s1.begin(),s1.end());
//     reverse(s2.begin(),s2.end());
//     reverse(s3.begin(),s3.end());
//         while(s3!="" &&( s1.length() || s2.length())){
//              if(!s1.length() && s2.length()){
//                  if(s2==s3) return true;
//                  return false;
//              }

//              if(s1.length() && !s2.length()){
//                  if(s1==s3) return true;
//                  return false;
//              }


//     if(s1[s1.length()-1]==s3[s3.length()-1] || s2[s2.length()-1]==s3[s3.length()-1] )
//             {
//                 if(s1[s1.length()-1]==s3[s3.length()-1] ){
//                     s1.pop_back();
//                     s3.pop_back();
//                 }
//                 else{
//                     s2.pop_back();
//                     s3.pop_back();
//                 }
//             }
//             else return false;
//         }

//        return true; 
//     }
// };




class Solution {
public:
    bool solve(string &s1, string &s2, string &s3,int ind1,int ind2,vector<vector<int>>&dp)
{
    if(ind1+ind2==s3.size()) return 1;
    if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
    bool ans=0;        
    if(ind1<s1.size() && s1[ind1]==s3[ind1+ind2]) 
    ans=(ans | solve(s1,s2,s3,ind1+1,ind2,dp));
    if(ind2<s2.size() && s2[ind2]==s3[ind1+ind2])
    ans=(ans | solve(s1,s2,s3,ind1,ind2+1,dp));
    return dp[ind1][ind2]=ans;
}
    bool isInterleave(string s1, string s2, string s3) {
         if(s1.size()+s2.size()!=s3.size()) return false;
    vector<vector<int>>dp(s1.size()+1,vector<int>(s2.size()+1,-1));
    return solve(s1,s2,s3,0,0,dp);
    }
};