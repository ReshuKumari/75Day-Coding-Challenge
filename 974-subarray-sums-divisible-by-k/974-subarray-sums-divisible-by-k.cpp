class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==0)
            return 0;
        int i=0, cnt=0;
        int cur_sum=0;
        unordered_map<int, int> mp;
        mp[0]=1;
        while(i<n)
        {
            cur_sum+=nums[i++];
            int rem=cur_sum%k;
            if(rem<0)
                rem+=k;
            if(mp.find(rem)!=mp.end())
                cnt+=mp[rem];
            mp[rem]++;
        }
        return cnt;
        
    }
};


//pre= 4 9 9 7 5 6
//mp[4]=1
//mp[4]=2
//mp[4]=3
//mp[2]=1
//mp[0]=1
//mp[1]=1