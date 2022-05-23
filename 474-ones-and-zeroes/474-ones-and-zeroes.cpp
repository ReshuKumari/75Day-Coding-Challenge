class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int dp[m+1][n+1];
        memset(dp, 0, sizeof(dp));
        for(auto &s:strs)
        {
            int ones=count(s.begin(), s.end(), '1');
            int zeroes=s.size()-ones;
            for(int i=m;i>=zeroes;i--)
            {
                for(int j=n;j>=ones;j--)
                {
                    dp[i][j]=max(dp[i][j], dp[i-zeroes][j-ones]+1);
                }
            }
        }
        return dp[m][n];
    }
};

/*vector<vector<int>> dp(m+1,vector<int>(n+1,0));
    
    for (auto &s: strs) {
        int ones = count(s.begin(), s.end(), '1');
        int zeros= s.size()-ones;
        for (int i=m; i>=zeros; i--) 
            for (int j=n; j>=ones; j--)
                dp[i][j] = max(dp[i][j], dp[i-zeros][j-ones]+1);
    }
    return dp[m][n];*/