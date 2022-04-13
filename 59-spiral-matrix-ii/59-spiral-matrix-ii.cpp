class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> v(n, vector<int>(n));
        int left=0, right=n-1, up=0, down=n-1, d=0;
        int x=1;
        while(left<=right && up<=down)
        {
            if(d==0)
            {
                for(int i=left;i<=right;i++)
                {
                    v[up][i]=x++;
                }
                d++;
                up++;
            }
            if(d==1)
            {
                for(int i=up;i<=down;i++)
                {
                    v[i][right]=x++;
                }
                d++;
                right--;
            }
            if(d==2)
            {
                for(int i=right;i>=left;i--)
                {
                    v[down][i]=x++;
                }
                d++;
                down--;
            }
            if(d==3)
            {
                for(int i=down;i>=up;i--)
                {
                    v[i][left]=x++;
                }
                d++;
                left++;
            }
            d=d%4;
        }
        return v;
    }
};