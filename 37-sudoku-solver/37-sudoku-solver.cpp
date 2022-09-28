class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
        return;
    }
    bool solve(vector<vector<char>>& board)
    {
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]=='.')
                {
                    for(int k='1';k<='9';k++)
                    {
                        if(isValid(board, i, j, k))
                        {
                            board[i][j]=k;
                            
                            if(solve(board))
                                return true;
                            else
                                board[i][j]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    bool isValid(vector<vector<char>>& board, int row, int col, char val)
    {
        for(int i=0;i<9;i++)
        {
            if(board[i][col]==val) return false;
            if(board[row][i]==val) return false;
            if(board[3*(row/3)+i/3][3*(col/3)+i%3]==val) return false;
        }
        return true;
    }
};