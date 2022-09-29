class Solution {
public:
    /*int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        vector<vector<int> > dp(nums.size(), vector<int>(nums.size(), 0));
        for (int i = nums.size() - 3; i >= 0; i --) {
            for (int j = i + 2; j < nums.size();j ++) {
                for (int k = i + 1; k < j; k ++)
                    dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + nums[i] * nums[k] * nums[j]);
            }
        }
        return dp[0][nums.size() - 1];
    }*/
    int maxCoins(vector<int>& nums)
    {
        vector<int> v;
        v.push_back(1);
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            v.push_back(nums[i]);
        }
        v.push_back(1);
        vector<vector<int>> dp(n+1, vector<int> (n+1,-1));
        return solve(v, 1, n, dp);
    }
    int solve(vector<int> &nums, int start, int end, vector<vector<int>> &dp)
    {
        if(start>end)
            return 0;
        //if(start==end)
          //  return nums[start-1]*nums[start]*nums[start+1];
        if (dp[start][end] >= 0) {
            return dp[start][end];
        }
        for(int i=start;i<=end;i++)
        {
            dp[start][end]=max(dp[start][end], nums[i]*nums[start-1]*nums[end+1]+solve(nums, start, i-1, dp)+solve(nums, i+1, end, dp));
        }
        return dp[start][end];
    }
};