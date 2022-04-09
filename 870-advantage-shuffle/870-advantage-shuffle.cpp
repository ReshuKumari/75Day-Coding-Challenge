class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        multiset<int> m;
        for(auto a:nums1)
            m.insert(a);
        for(int i=0;i<nums2.size();i++)
        {
            auto a=m.upper_bound( nums2[i]);
            if(a == m.end()) a =m.begin();
            nums1[i]=*a;
            m.erase(a);
        }
        return nums1;
    }
};