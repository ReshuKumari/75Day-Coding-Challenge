class Solution {
public:
    int num(int n)
    {
        return log2(n)+1;
    }
    int concatenatedBinary(int n) {
        long ans=0, mod=1000000007;
        for(int i=1;i<=n;++i)
        {
            int no=num(i);
            ans=((ans<<no)%mod+i)%mod;
        }
        return ans;
    }
};