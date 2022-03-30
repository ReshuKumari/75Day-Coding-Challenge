class Solution {
public:
    int maxVowels(string s, int k) {
        string v="aeiou";
        int pre=0, res=0, cur=0;
        for(int i=0;i<s.size();i++) {
            if(v.find(s[i])!=std::string::npos) cur++;
            if(i>=k&&v.find(s[i-k])!=std::string::npos) cur--;
            res=max(res, cur);            
        }
        return res;
    }
};