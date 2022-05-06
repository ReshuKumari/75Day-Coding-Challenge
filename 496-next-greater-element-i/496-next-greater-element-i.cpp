class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        stack<int> s;
        int n=nums2.size();
        for(int i=n-1;i>=0;i--)
        {
            while(!s.empty() && s.top()<nums2[i])
            {
                s.pop();
            }
            if(s.empty())
            {
                mp[nums2[i]]=-1;
            }
            else
            {
                mp[nums2[i]]=s.top();
            }
            s.push(nums2[i]);
        }
        vector<int> ans;
        for(auto i:nums1)
        {
            ans.push_back(mp[i]);
        }
        return ans;
    }
};