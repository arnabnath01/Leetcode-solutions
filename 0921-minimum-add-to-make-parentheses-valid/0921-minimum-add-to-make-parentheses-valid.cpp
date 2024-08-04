class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>st;
        // int open=0.close=0;
        for(auto c:s)
        {
            if(!st.empty()&&st.top()=='('){
                if(c==')')
                st.pop();
                else
                st.push(c);
            }
            else{
                st.push(c);
            }
        }
        return st.size();
    }
};