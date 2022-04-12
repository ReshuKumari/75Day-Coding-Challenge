// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
public:
    string chooseandswap(string str){
        // Code Here
        vector<int> vec(26,-1);
        int n=str.size();
        for(int i=0;i<n;i++)
        {
            if(vec[str[i]-'a']==-1)
            vec[str[i]-'a']=i;
        }
        int i;
        char ch,ch1;
        for(i=0;i<n;i++)
        {
            bool flag=0;
            for(int j=0;j<str[i]-'a';j++)
            {
                if(vec[j]>vec[str[i]-'a'])
                {
                    ch=j+'a';
                    ch1=str[i];
                    flag=1;
                    break;
                }
            }
            if(flag)
            break;
        }
        if(i<n)
        {
            for(int j=0;j<n;j++)
            {
                if(str[j]==ch)
                str[j]=ch1;
                else if(str[j]==ch1)
                str[j]=ch;
            }
        }
        return str;
    }
    
};


// { Driver Code Starts.

int main()
{
    Solution obj;
	int t;
	cin >> t;
	while(t--)
	{	
	    string a;
		cin >> a;
		cout << obj.chooseandswap(a) << endl;
	}
	return 0;
}
  // } Driver Code Ends