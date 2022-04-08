class Solution {
public:
    bool canJump(vector<int>& nums) {
         int n = nums.size(), farest = 0;
          for(int i = 0;i < n; i++)
          {
            if(farest < i) return false;
            farest = max(i + nums[i], farest);
          }

          return true;
    }
};