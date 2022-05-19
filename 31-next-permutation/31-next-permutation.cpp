class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int first;
        for(first=n-2;first>=0;first--)
        {
            if(nums[first]<nums[first+1])
            {
                break;
            }
        }
        if(first<0)
        {
            reverse(nums.begin(), nums.end());
        }
        else
        {
            int second=n-1;
            for(second=n-1;second>first;second--)
            {
                if(nums[second]>nums[first])
                {
                    break;
                }
            }
            swap(nums[first], nums[second]);
            reverse(nums.begin()+first+1, nums.end());
        }
    }
};