class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> m;
        for(auto i:nums1)
            m[i]++;
        vector<int> res;
        for (auto a : nums2)
            if (m.count(a)) {
                res.push_back(a);
                m[a]--;
                if(m[a]==0)
                m.erase(a);
            }
        return res;
    }
};