class Solution {
public:
    
    /*int row, col;
    vector<int> dx={1,-1, 0,0};
    vector<int> dy={0,0,1, -1};
    
    bool valid(int x, int y)
    {
        return (x<row && y<col && x>=0 && y>=0);
    }
    int  dfs(vector<vector<int>> &matrix, int x, int y, vector<vector<int>> &dp)
    {
        if(dp[x][y]!=-1)
            return dp[x][y];
        int max_len=0;
        for(int i=0;i<4;i++)
        {
            int nx=dx[i]+x;
            int ny=dy[i]+y;
            if(valid(nx, ny) && matrix[nx][ny]>matrix[x][y])
            {
                int l=1+dfs(matrix, nx, ny, dp);
                    max_len=max(max_len, l);
            }
        }
        dp[x][y]=max_len;
        return max_len;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        row=matrix.size();
        if(row==0)
            return 0;
        col=matrix[0].size();
            vector<vector<int>> dp(row, vector<int>(col, -1));
        int max_len=0;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                int l=dfs(matrix, i, j, dp);
                max_len=max(max_len, l+1);
            }
        }
        return max_len;
    }*/
    
    
    int dp[200][200]{};
    int maxPath, n,m;
    int longestIncreasingPath(vector<vector<int>> &matrix)
    {
        maxPath=0, n=matrix.size(), m=matrix[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                maxPath=max(maxPath, solve(matrix, i,j, -1));
            }
        }
        return maxPath;
    }
    int solve(vector<vector<int>> &mat, int i, int j, int prev)
    {
        if(i<0 || j<0 || i>=n || j>=m || mat[i][j]<=prev)
            return 0;
        if(dp[i][j])
            return dp[i][j];
        return dp[i][j]= 1+max({solve(mat, i+1,j,mat[i][j]),
                               solve(mat, i-1,j,mat[i][j]),
                               solve(mat, i, j+1, mat[i][j]),
                               solve(mat, i, j-1, mat[i][j])});
    }
};