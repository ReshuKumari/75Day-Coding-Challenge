class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n = s.size();
        if(n<k) return s;
        
        stack<pair<char,int>> stk;
        for(int i=0; i<n; ++i){
            if(stk.empty() || stk.top().first != s[i]) 
                stk.push({s[i],1});
            else{
                auto prev = stk.top();
                stk.pop();
                stk.push({s[i], prev.second+1});
            }
            if(stk.top().second==k) stk.pop();
        }
        string ans="";
        while(!stk.empty())
        {
            int x=stk.top().second;
            for(int i=0;i<x;i++)
                ans+=stk.top().first;
            stk.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};