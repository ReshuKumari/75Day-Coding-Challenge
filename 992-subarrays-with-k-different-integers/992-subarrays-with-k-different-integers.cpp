class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmost(nums,k)-atmost(nums,k-1);
    }
    int atmost(vector<int> &nums, int k)
    {
        map<int, int> mp;
        int i=0, j=0, n=nums.size(), ans=0;
        while(j<n)
        {
            mp[nums[j]]++;
            while(mp.size()>k)
            {
                mp[nums[i]]--;
                if(mp[nums[i]]==0)
                    mp.erase(nums[i]);
                i++;
            }
            ans+=(j-i+1);
            j++;
        }
        return ans;
    }
};