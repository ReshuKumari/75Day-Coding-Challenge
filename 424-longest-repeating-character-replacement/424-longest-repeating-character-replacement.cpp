class Solution {
public:
    int characterReplacement(string s, int k) {
        int size=s.size(), ret=0;
        vector<int> count(26, 0);
        int start=0, end=0, globalMaxFreq=0;
        for(;end<size;end++)
        {
            count[s[end]-'A']+=1;
            globalMaxFreq=max(globalMaxFreq, count[s[end]-'A']);
            if((end-start+1)-globalMaxFreq > k)
            {
                ret=max(ret, (end-start));
                count[s[start]-'A']-=1;
                start+=1;
            }
        }
        return max(ret, end-start);
    }
};