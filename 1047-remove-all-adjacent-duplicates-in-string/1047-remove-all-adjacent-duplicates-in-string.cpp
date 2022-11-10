class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        st.push(s[0]);
        int i=1, n=s.size();
        while(i<n)
        {
            if(!st.empty() && s[i]==st.top())
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