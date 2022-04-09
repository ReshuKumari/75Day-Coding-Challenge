class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> mp;
        int max_freq=0;
        for(auto a:tasks)
        {
            mp[a]++;
            max_freq=max(max_freq, mp[a]);
        }
        int ans=(max_freq-1)*(n+1);
        for(auto e:mp)
        {
            if(e.second==max_freq)
                ans++;
        }
        return max((int)tasks.size(), ans);
        
    }
};