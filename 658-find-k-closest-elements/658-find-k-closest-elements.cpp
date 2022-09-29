class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n=arr.size();
        int l=0, r=n-k;
        while(l<r)
        {
            int mid=(l+r)/2;
            if(x-arr[mid] <= arr[mid+k]-x)
                r=mid;
            else
                l=mid+1;
        }
        return vector<int>(arr.begin()+l, arr.begin()+l+k);
    }
};