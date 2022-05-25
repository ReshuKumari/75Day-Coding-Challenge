class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](vector<int> &a, vector<int> &b){
            return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);});
        vector<int> dp;
        for (auto e : envelopes)
        {
            auto iter = lower_bound(dp.begin(), dp.end(), e[1]);
            if (iter == dp.end())
                dp.push_back(e[1]);
            else if (e[1] < *iter)
                *iter = e[1];
        }
        return dp.size();
    }
};