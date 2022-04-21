class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty()==true)
        {
            return {-1,-1};
        }
        int l=-1, r=-1;
        int low=0, high=nums.size()-1, mid;
        while(low<=high)
        {
            mid=low+(high-low)/2;
            if(nums[mid]==target)
            {
                l=mid, r=mid;
                for(int i=mid;i>=0;i--)
                {
                    if(nums[i]==target)
                        l=i;
                    else
                    {
                        break;
                    }
                }
                for(int i=mid;i<nums.size();i++)
                {
                    if(nums[i]==target)
                        r=i;
                    else
                    {
                        break;
                    }
                }
                return {l,r};
            }
            else if(nums[mid]>target)
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return {l,r};
    }
};