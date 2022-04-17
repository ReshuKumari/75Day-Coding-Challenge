class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n=citations.size();
        int i,total=0;
        vector<int> num(n+1,0);

        for(i=0;i<n;i++)
        {
            if(citations[i]<n+1)
                num[citations[i]]++;
            else
                num[n]++;
        } 
        for(i=n;i>=0;i--){
            if(num[i])
                total+=num[i];
            if(total>=i)
                return i;
        } 
        return 0;
    }
};