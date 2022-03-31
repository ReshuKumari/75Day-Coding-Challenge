class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        for(int &x:nums)
            x=x%2;
        unordered_map <int,int> mp;
        mp[0]=1;
        int csum=0;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            csum+=nums[i];
            if(mp.count(csum-k))
                ans+=mp[csum-k];
            mp[csum]++;
        }
        return ans;
    }
};