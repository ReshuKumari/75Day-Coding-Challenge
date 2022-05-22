class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        unordered_set<int> s(nums.begin(), nums.end());
        int res=1;
        for(int n:nums)
        {
            if(s.find(n)==s.end())
                continue;
            s.erase(n);
            int prev=n-1, next=n+1;
            while(s.find(prev)!=s.end())
                s.erase(prev--);
            while(s.find(next)!=s.end())
                s.erase(next++);
            res=max(res, next-prev-1);
        }
        return res;
    }
};