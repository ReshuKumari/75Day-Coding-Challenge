class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low=0, mid=0, high=nums.size()-1;
        int n=nums.size();
        while(mid<=high)
        {
            int x=nums[mid];
            if(x==0)
            {
                swap(nums[low], nums[mid]);
                low++; mid++;
            }
            else if(x==2)
            {
                swap(nums[mid], nums[high]);
                high--;
            }
            else
            {
                mid++;
            }
        }
        
    }
};