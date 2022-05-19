class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int i;
        for(i=n-2;i>=0;i--)
        {
            if(nums[i]<nums[i+1])
            {
                break;
            }
        }
        if(i<0)
        {
            reverse(nums.begin(), nums.end());
        }
        else
        {
            int k=n-1;
            for(k=n-1;k>i;k--)
            {
                if(nums[k]>nums[i])
                {
                    break;
                }
            }
            swap(nums[i], nums[k]);
            reverse(nums.begin()+i+1, nums.end());
        }
    }
};