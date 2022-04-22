class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        return helper(nums,0, nums.size()-1);
    }
    int helper(vector<int> &nums,int low, int high)
    {
        if(low==high)
        {
            return low;
        }
        else
        {
            int mid=(low+high)/2;
            if(nums[mid+1]<nums[mid])
                return helper(nums, low, mid);
            else
                return helper(nums, mid+1, high);
        }
    }
};