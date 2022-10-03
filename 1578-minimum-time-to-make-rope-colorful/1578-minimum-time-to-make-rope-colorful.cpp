class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n=colors.size(), ans=0;
        int left=0;
        while(left<n)
        {
            int right=left, maxcost=INT_MIN, totalcost=0;
            while(colors[left]==colors[right]&& right<n)
            {
                totalcost+=neededTime[right];
                maxcost=max(maxcost, neededTime[right]);
                right++;
            }
            left=right;
            ans+=(totalcost-maxcost);
        }
        return ans;
    }
};