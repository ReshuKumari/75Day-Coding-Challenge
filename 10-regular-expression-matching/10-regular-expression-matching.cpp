class Solution {
public:
    bool isMatch(string s, string p) {
        /*int n=s.size(), m=p.size();
        vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));
        //if both pattern and string empty
        dp[0][0]=true;
        //if pattern empty string not empty
        for(int i=1;i<=n;i++)
        {
            dp[i][0]=false;
        }
        //if pattern not empty and string empty
        for(int i=1;i<=m;i++)
        {
            bool flag=true;
            for(int j=1;j<=i;j++)
            {
                if(p[j-1]!='*')
                {
                    flag=false;
                    break;
                }
            }
            dp[0][i]=flag;
        }
        //for all cases
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                //if si == pi or pi==? case
                if(s[i-1]==p[j-1] || p[j-1]=='.')
                    dp[i][j]=dp[i-1][j-1];
                else if(p[j-1]=='*')
                {
                    dp[i][j]=dp[i-1][j] | dp[i][j-1];
                }
                else
                    dp[i][j]=false;
            }
        }
        return dp[n][m];*/
        
        
         if (s.size() == 0 || p.size() == 0) {
        return false;
    }
    //bool dp[s.length()+1][p.length()+1];
        int n=s.size(), m=p.size();
        vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));
    dp[0][0] = true;
    for (int i = 0; i < p.length(); i++) {
        if (p[i] == '*' && dp[0][i-1]) {
            dp[0][i+1] = true;
        }
    }
    for (int i = 1 ; i <= s.length(); i++) {
        for (int j = 1; j <= p.length(); j++) {
            if (s[i-1] == p[j - 1] || p[j - 1] == '.') {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                if (p[j - 1] == '*') {
                    if (s[i - 1] != p[j - 2] && p[j - 2] != '.') {
                        dp[i][j] = dp[i][j - 2];
                    } else {
                        dp[i][j] = dp[i - 1][j] || dp[i][j - 1] || dp[i][j - 2];
                    }
                }
        }
    }
    return dp[s.length()][p.length()];
    }
};