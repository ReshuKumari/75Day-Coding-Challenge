class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]]++;
        }
        priority_queue<pair<int, char>> v;
        for(auto a:mp)
        {
            v.push({a.second, a.first});
        }
        string ans="";
        while(!v.empty())
        {
            int num=v.top().first;
            char c=v.top().second;
            v.pop();
            for(int i=0;i<num;i++)
            {
                ans+=c;
            }
        }
        return ans;
    }
};