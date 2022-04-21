class Solution {
public:
    int mySqrt(int x) {
        int low=1, high=x;
        int long mid;
        while(low<=high)
        {
            mid=low+(high-low)/2;
            if(x/mid >= mid)
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return low-1;
    }
};