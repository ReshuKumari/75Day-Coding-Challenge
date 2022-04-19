class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        map<int, int> mp;
        for(int i=0;i<intervals.size();i++)
        {
            mp[intervals[i][0]]=i;
        }
        vector<int> ans(intervals.size());
        for(int i=0;i<intervals.size();i++)
        {
            if(mp.lower_bound(intervals[i][1])!=mp.end())
            {
                ans[i]=mp.lower_bound(intervals[i][1])->second;
            }
            else
            {
                ans[i]=-1;
            }
        }
        return ans;
    }
};