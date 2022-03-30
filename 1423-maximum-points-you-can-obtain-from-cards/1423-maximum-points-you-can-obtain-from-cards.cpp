class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int total=0;
        int n=cardPoints.size();
        for(int i=0;i<n-k;i++)
            total+=cardPoints[i];
        int ans=total;
        for(int i=n-k;i<n;i++)
        {
            
            total=total+cardPoints[i]-cardPoints[i-(n-k)];
            ans=min(ans,total);
        }
        int sum=0;
        for(int i=0;i<n;i++)
            sum+=cardPoints[i];
        return sum-ans;
    }
};