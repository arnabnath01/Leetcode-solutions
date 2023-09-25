class Solution {
public:
    char findTheDifference(string s, string t) {
        if(s.empty()) return t[0];
        int res=0;
        for(int i=0;i<s.length();i++)
        {
            res^=s[i];
            //   cout<<"======"<<res<<"======"<<endl;
        }

        // cout<<"==================================================="<<endl;
        for(int i=0;i<t.length();i++)
        {
            res^=t[i];
            // cout<<"======"<<res<<"======"<<endl;
        }

        return (char)res;

    }
};