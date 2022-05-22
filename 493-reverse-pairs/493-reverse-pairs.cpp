class Solution {
public:
    long long int res=0;
void merge(vector<int> &arr, int l, int m, int r)
{
	int i = l, j = m + 1;
        while(i <= m and j <= r) {
            if((long)arr[i] > (long)2 * arr[j]) {
                res += (m + 1 - i);
                j++;
            }else {
                i++;
            }
        }
        sort(arr.begin() + l, arr.begin() + r + 1);
        return;
}
void mergeSort(vector<int> &arr, int l, int r)
{
	if(l>=r)
		return;
	int mid=(l+r)/2;
	mergeSort(arr, l, mid);
	mergeSort(arr, mid+1, r);
	merge(arr, l, mid, r);
}

int reversePairs(vector<int>& arr) {
    int n=arr.size();
        mergeSort(arr, 0, n-1);
	return res;
    }
};