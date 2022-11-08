class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        st.push(s[0]);
        int i=1;
        while(i<s.size())
        {
            if(!st.empty() && (st.top()-32==s[i] || st.top()==s[i]-32))
            {
                st.pop(); 
            }
            else
            {
                st.push(s[i]);
            }
            i++;
        }
        string ans="";
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};