class Solution {
public:
    int maxProduct(vector<int>& nums) {
          int ans=nums[0], mini=nums[0], maxi=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]<0)
            {
               swap(maxi, mini);
            }
            maxi=max(nums[i], maxi*nums[i]);
            mini=min(nums[i], mini*nums[i]);
            ans=max({ans, maxi, mini});
        }
        return ans;
    }
};
// edge cases -  -1 -2 -3
//        7 8 0 -5 6