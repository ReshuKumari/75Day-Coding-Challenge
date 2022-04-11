class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> ans(n,vector<int>(m));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                int J=(j+k)%m; // (j + numbers of columns added)%m
                
                int I=(i+(j+k)/m)%n; // (i + numbers of rows added)%n 
                
                ans[I][J]=grid[i][j];
            }
        }
        return ans;
    }
};