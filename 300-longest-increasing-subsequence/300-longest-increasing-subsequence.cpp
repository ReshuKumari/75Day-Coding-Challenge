class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
         vector<int> v;
        for(int i=0;i<nums.size();i++)
        {
            if(v.empty() || nums[i]>v.back())
            {
                v.push_back(nums[i]);
            }
            else
            {
                int ind=lower_bound(v.begin(), v.end(), nums[i])-v.begin();
                v[ind]=nums[i];
            }
        }
        return v.size();
    }
};