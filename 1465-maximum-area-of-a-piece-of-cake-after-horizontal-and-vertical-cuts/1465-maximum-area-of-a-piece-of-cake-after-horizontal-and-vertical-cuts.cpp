class Solution {
public:
    int getmax(int h, vector<int> &height)
    {
        sort(height.begin(), height.end());
        int n=height.size();
        int ans=max(h-height[n-1], height[0]);
        for(int i=1;i<n;i++)
            ans=max(ans, height[i]-height[i-1]);
        return ans;
    }
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        int a=getmax(h, horizontalCuts);
        int b=getmax(w, verticalCuts);
        //return (int)((long)a*(long)b)%1000000007;
        return (int)((long)a*b%1000000007);

    }
};