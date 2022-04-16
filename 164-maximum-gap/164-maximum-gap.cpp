class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n=nums.size();
        if(n<2)
            return 0;
        int maxi=*max_element(nums.begin(), nums.end());
        int mini=*min_element(nums.begin(), nums.end());
        int gap = (int)ceil((double)(maxi - mini)/(n - 1));
        vector<int> bucketmax(n-1, INT_MIN), bucketmin(n-1, INT_MAX);
        for(int i=0;i<n;i++)
        {
            if(nums[i]==maxi || nums[i]==mini)
                continue;
            int x=(nums[i]-mini)/gap;
            bucketmin[x]=min(bucketmin[x], nums[i]);
            bucketmax[x]=max(bucketmax[x], nums[i]);
        }

        int maxGap = INT_MIN;
        int previous = mini;
        for (int i = 0; i < n - 1; i++) {
            if (bucketmin[i] == INT_MAX && bucketmax[i] == INT_MIN)
                continue;
            maxGap = max(maxGap, bucketmin[i] - previous);
            previous = bucketmax[i];
        }
        maxGap = max(maxGap, maxi - previous);
        return maxGap;
    }
};