class Solution {
public:
    int maximum69Number (int num) {
        string s=to_string(num);
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='6')
            {
                s[i]='9';
                break;
            }
        }
        int n=0; //s=9969
        //cout<<s<<endl;
        for(int i=0;i<s.size();i++)
        {
            if(i>0)
            {n=n*10+s[i]-'0'; }
            else
            {n=s[i]-'0'; }
        }
        return n;
    }
};