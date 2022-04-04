class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<long long> prefix_sum(n+1, 0);
        for(int i=0;i<n;i++)
            prefix_sum[i+1]=prefix_sum[i]+nums[i];
        deque<int> dq;
        int res=n+1;
        for(int i=0;i<n+1;i++)
        {
            while(!dq.empty() && prefix_sum[i]-prefix_sum[dq.front()] >= k)
            {
                res=min(res, i-dq.front());
                dq.pop_front();
            }
            while(!dq.empty() && prefix_sum[i] <= prefix_sum[dq.back()])
            {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        return res=res>n?-1:res;
    }
};