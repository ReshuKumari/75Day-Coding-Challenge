class Solution {
public:
    int kIncreasing(vector<int>& arr, int k) {
        int n = arr.size();
        int ans = 0;
        for (int i = 0; i < k; ++i) {
            vector<int> newArr;
            for (int j = i; j < n; j += k)
                newArr.push_back(arr[j]);
            ans += newArr.size() - longestNonDecreasingSubsequence(newArr);
        }
        return ans;
    }
    int longestNonDecreasingSubsequence(vector<int> &arr)
    {
        vector<int> dq;
        dq.push_back(arr[0]);
        for(int i=1;i<arr.size();i++)
        {
            if(dq.back() <= arr[i])
            {
                dq.push_back(arr[i]);
            }
            else
            {
                int idx = upper_bound(dq.begin(), dq.end(), arr[i]) - dq.begin(); // Find the index of the smallest number > x
                dq[idx] = arr[i];
            }
        }
        return dq.size();
    }
};