class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<long long> dp(n,0);
        dp[0]=1;
        vector<int> count(primes.size(), 0);
        for(int i=1;i<n;i++)
        {
            long long val=LONG_MAX;
            for(int j=0;j<primes.size();j++)
            {
                val=min(val, dp[count[j]]*primes[j]);
            }
            dp[i]=val;
            for(int j=0;j<primes.size();j++)
            {
                if(dp[i]==dp[count[j]]*primes[j])
                    count[j]++;
            }
        }
        return dp[n-1];
    }
};