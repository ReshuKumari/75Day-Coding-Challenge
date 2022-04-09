class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(auto a:nums)
            mp[a]++;
        priority_queue<pair<int, int>> pq;
        vector<int> ans;
        for(auto a:mp)
        {
            pq.push({a.second, a.first});
            if(pq.size()>(int)mp.size() - k)
            {
                ans.push_back(pq.top().second);
                pq.pop();
            }
        }
        return ans;
    }
};