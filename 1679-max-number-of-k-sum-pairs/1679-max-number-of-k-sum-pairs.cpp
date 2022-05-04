class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        int res = 0;
        for (int n : nums) {
            if (map[k - n] > 0) {
                res++;
                map[k - n]--;
            } else {
                map[n]++;
            }
        }
        return res;
    }
};