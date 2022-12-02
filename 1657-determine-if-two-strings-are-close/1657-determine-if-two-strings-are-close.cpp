class Solution {
public:
    bool closeStrings(string word1, string word2) {
        map<char, int> mp1, mp2;
        for(int i=0;i<word1.size();i++)
        {
            mp1[word1[i]]++;
        }
        for(int i=0;i<word2.size();i++)
        {
            mp2[word2[i]]++;
        }
        vector<int> v1, v2;
        vector<char> s1, s2;
        for(auto a: mp1)
        {
            v1.push_back(a.second);
            s1.push_back(a.first);
        }
        for(auto a: mp2)
        {
            v2.push_back(a.second);
            s2.push_back(a.first);
        }
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        if(v1==v2 && s1==s2)
            return true;
        return false;
    }
};