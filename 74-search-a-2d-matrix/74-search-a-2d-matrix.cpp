class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(), m=matrix[0].size();
        int len=n*m-1;
        int low=0, high=len;
        while(low!=high)
        {
            int mid=(low+high-1)/2;
            if(matrix[mid/m][mid%m] < target)
                low=mid+1;
            else
                high=mid;
        }
        return matrix[high/m][high%m] == target;
    }
};