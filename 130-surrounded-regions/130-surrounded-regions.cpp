class Solution {
public:
    int n,m;
    void dfs(vector<vector<char>>& board, int i, int j)
    {
        if(i<0 || i>=n || j<0 || j>=m || board[i][j]=='X'|| board[i][j]=='#')
        {   return; }
        board[i][j]='#';
        dfs(board, i-1,j);
        dfs(board, i, j+1);
        dfs(board, i+1, j);
        dfs(board, i, j-1);
        //return;
    }
    void solve(vector<vector<char>>& board) {
        if(board.size()==0)
        return;
      n=board.size(), m=board[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if((i==0 || i==n-1 || j==0 || j==m-1) && board[i][j]=='O')
                {
                    dfs(board, i, j);
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]=='O')
                {board[i][j]='X'; }
                else if(board[i][j]=='#')
                {    board[i][j]='O'; }
            }
        }
        return;
    }
};