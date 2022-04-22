class Solution {
public:
    int hIndex(vector<int>& citations) {
        if (citations.size() == 0) {
		return 0;
	    }
        int low=0, high=citations.size()-1;
        int mid,ans;
        int n=citations.size();
        while(low<=high)
        {
            mid=(high+low)>>1;
            if (citations[mid] == n - mid) 
			return citations[mid];
            else if(citations[mid]>n-mid)
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        
        }
        return n-low;
    }
};