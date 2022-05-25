class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        if(n==0)
            return 0;
        int start=0, maxlen=1;
        for(int i=0;i<n;i++)
        {
            int low=i-1, high=i+1;
            while(high < n && s[i]==s[high] )
            {
                high++;
            }
            while(low >= 0 && s[i]==s[low])
            {
                low--;
            }
            while(low >= 0 && high < n && s[high]==s[low])
            {
                high++; low--;
            }
            int len=high-low-1;
            if(len>maxlen)
            {
                maxlen=len;
                start=low+1;
            }
        }
        return s.substr(start, maxlen);
    }
};