class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> v;
        int i=0;
        sort(candidates.begin(), candidates.end());
        sum(i,candidates, target,v,ans);
        return ans;
    }
   void sum(int i,vector<int>& candidates, int target, vector<int> &v, vector<vector<int>> &ans)
   {
       if(target == 0) 
        {
            ans.push_back(v); // include that combination in our answer
            return; // and then return, we are now not gonna explore more possiblity
        }
       
        if(target < 0)
            return;
      
        if(i == candidates.size())
            return;
       
        sum(i + 1, candidates, target, v, ans);
        v.push_back(candidates[i]); // including ith element
        sum(i, candidates, target - candidates[i], v, ans);
        v.pop_back();
   }
};