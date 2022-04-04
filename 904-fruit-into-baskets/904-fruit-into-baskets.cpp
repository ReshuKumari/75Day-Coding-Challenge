class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int i=0, j=0, n=fruits.size();
        int ans=0;
        unordered_map<int, int> mp;
        while(j<n)
        {
            if(mp.find(fruits[j])!=mp.end()) //already there in map
            {
                mp[fruits[j]]++;
            }
            else //not there in map
            {
                mp[fruits[j]]++;
            }
            while(mp.size()>2)
            {
                mp[fruits[i]]--;
                if(mp[fruits[i]]==0)
                {
                    mp.erase(fruits[i]);
                }
                i++;
            }
            ans=max(ans, j-i+1);
            j++;
        }
        return ans;
    }
};