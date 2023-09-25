class Solution {
public:
    char findTheDifference(string s, string t) {
        if(s.empty()) return t[0];

        unordered_map<char,int>mp1;
        for(auto x:t)
        mp1[x]++;
        for(auto x:s)
        mp1[x]--;
    for(auto x:mp1)
    {
        if(x.second) return x.first;
    }
       return ' ';
    }
};