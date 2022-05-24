class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        //(y-x, x)
        deque<vector<int>> dq;
        int ans=INT_MIN;
        for(vector<int>& point:points)
        {
            int x=point[0], y=point[1];
            while(!dq.empty() && x-dq.front()[1]> k)
            {
                dq.pop_front();
            }
            if(!dq.empty())
            {
                ans=max(ans, dq.front()[0]+(y+x));
            }
            while(!dq.empty() && dq.back()[0] <= y-x)
            {
                dq.pop_back();
            }
            dq.push_back({y-x, x});
        }
        return ans;
    }
};