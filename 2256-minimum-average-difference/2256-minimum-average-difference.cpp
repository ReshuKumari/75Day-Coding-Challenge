class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n=nums.size();
        vector<long long> c(n,0);
        c[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            c[i]=c[i-1]+nums[i];
            //cout<<c[i]<<" ";
        }
        int ans=0, temp=INT_MAX;
        //cout<<endl;
        for(int i=0;i<n;i++)
        {
            //cout<<c[i]<<" "<<i+1<<" "<<c[n-1]-c[i]<<" "<<n-i-1<<endl;
            int nn=(n-i-1)==0?1:(n-i-1);
            int val=abs((int)(c[i]/(i+1)) - (int)((c[n-1]-c[i])/nn));
            //cout<<val<<endl;
            if(temp>val)
            {
                temp=val;
                ans=i;
            }
            
        }
        return ans;
    }
};