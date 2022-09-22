class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        string temp="";
        int n=s.size();
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==' ')
            {
                reverse(temp.begin(), temp.end());
                ans+=temp+" ";
                temp="";
            }
            else
            {
                temp+=s[i];
            }
        }
        reverse(temp.begin(), temp.end());
        ans+=temp;
        return ans;
    }
};