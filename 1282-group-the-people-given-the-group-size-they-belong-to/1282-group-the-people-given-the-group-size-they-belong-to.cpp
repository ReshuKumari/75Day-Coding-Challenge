class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& g) {
      /*  vector<vector<int>> res, groups(groupSizes.size() + 1);
      for (auto i = 0; i < groupSizes.size(); ++i) {
        groups[groupSizes[i]].push_back(i);
        if (groups[groupSizes[i]].size() == groupSizes[i]) {
          res.push_back({});
          swap(res.back(), groups[groupSizes[i]]);
        }
      }
      return res;*/
        
        
        /*unordered_map<int, vector<int>> mp;
        for(int i=0;i<groupSizes.size();i++)
        {
            mp[groupSizes[i]].push_back(i);
        }
        vector<vector<int>> ans;
        for(auto a:mp)
        {
            int x=a.first, b=a.second.size(), cnt=0;
            vector<int> v=a.second;
            vector<int> vec;
            for(int i=0;i<b;i++)
            {
                
                vec.push_back(v[i]);
                cnt++;
                if(cnt==x)
                {
                    ans.push_back(vec);
                    cnt=0;
                    vec.clear();
                }
            }
        }
        return ans;*/
        vector<vector<int>>ans;
        unordered_map<int,vector<int>>m;
        for(int i=0;i<g.size();i++)
        {
			m[g[i]].push_back(i);
			if(m[g[i]].size()==g[i])
            {
                ans.push_back(m[g[i]]);
                m[g[i]].clear();
            }
        }
        return ans; 
    }
};