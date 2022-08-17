class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        return (int)((sqrt(grades.size() * 8 + 1) - 1)/2);
    }
};