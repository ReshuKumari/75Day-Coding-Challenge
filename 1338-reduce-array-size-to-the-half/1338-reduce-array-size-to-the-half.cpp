class Solution {
public:
    int minSetSize(vector<int>& arr) {
        map<int, int> mp;
        for(auto a:arr)
        {
            mp[a]++;
        }
        int ans=0;
        int n=arr.size();
        vector<pair<int, int>> v;
        for(auto a:mp)
        {
            v.push_back({a.first, a.second});
        }
        sort(v.begin(), v.end(),[](auto a, auto b){
            return a.second>b.second;
        });
        int x=n;
        for(int i=0;i<v.size();i++)
        {
            x-=v[i].second;
            ans++;
            if(x<=n/2)
            {
                return ans;
            }
        }
        return ans;
    }
};