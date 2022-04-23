class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int low=1, high=1000000000;
        int ans=INT_MAX;
        while(low<=high)
        {
            long long mid=low+(high-low)/2;
            if(isvalid(mid, piles,h))
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return low;
    }
    bool isvalid(long long k, vector<int>& piles, int h)
    {
        /*int cnt=0;
        for(int i=0;i<piles.size();i++)
        {
            cnt+=ceil(piles[i]/mid);
        }
        if(cnt<=h)
            return true;
        else
            return false;*/
        int hours = 0;
        for(int pile : piles){
            int div = pile / k;
            hours += div;
            if(pile % k != 0) hours++;
        }
        return hours <= h;
    }
};