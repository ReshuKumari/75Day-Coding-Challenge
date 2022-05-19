class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        ans[0]={1};
        for(int i=1;i<numRows;i++)
        {
            vector<int> v(ans[i-1].size()+1,0);
            v[v.size()-1]=1;
            v[0]=1;
            for(int j=1;j<v.size()-1;j++)
            {
                v[j]=ans[i-1][j-1]+ans[i-1][j];
            }
            ans[i]=v;
        }
        return ans;
    }
};