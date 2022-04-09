class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<int> stk;
        int l=0,r=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                stk.push(i);
                l++;
            }
            else if(!stk.empty()&& s[i]==')')
            {    stk.pop(); l--;    }
        }
        int unmatchedl=s.size();
        while(!stk.empty())
            stk.pop();
        for(int i=s.size()-1;i>=0;i--)
        {
            if(s[i]==')')
            {
                stk.push(i);
                r++;
            }
            else if(!stk.empty()&& s[i]=='(')
            {
                stk.pop(); l--;
            }
                
        }
        int unmatchedr=stk.size();
        //return unmatchedl+unmatchedr;
        return l+r;
    }
};