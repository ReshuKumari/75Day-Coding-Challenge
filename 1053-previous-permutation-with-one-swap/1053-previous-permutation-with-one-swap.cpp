class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        /*int n = arr.size(), k, l;
    	for (k = n - 2; k >= 0; k--) {
            if (arr[k] > arr[k + 1]) {
                break;
            }
        }
    	if (k < 0) {
    	    //reverse(arr.begin(), arr.end());
            return arr;
    	} else {
    	    for (l = n - 1; l > k; l--) {
                if (arr[l] < arr[k]) {
                    break;
                }
            } 
    	    swap(arr[k], arr[l]);
    	    reverse(arr.begin() + k + 1, arr.end());
        }
        return arr;*/
        int l = -1, n= arr.size();
        for(int i = n-1; i>0; i--){
            if(arr[i-1]>arr[i]){
                l = i-1;
                break;
            }
        }
        if(l == -1)
            return arr;
        int r = l+1;
        for(int i = l+1; i<n; i++){
            if(arr[i]< arr[l] && arr[r] < arr[i]) 
                r = i;
        }
        swap(arr[l], arr[r]);
        return arr;
    }
};