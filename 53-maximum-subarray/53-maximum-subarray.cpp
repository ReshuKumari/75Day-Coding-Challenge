class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=nums[0], tempans=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(tempans>0)
            {
                tempans+=nums[i];
            }
            else
            {
                tempans=nums[i];
            }
            ans=max(ans, tempans);
        }
        return ans;
    }
};