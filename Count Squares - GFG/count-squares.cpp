// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int countSquares(int N) {
        // code here
        int s=1,e=N;
          int ans=-1;
          while(s<=e){
              int mid=s+(e-s)/2;
              if( mid*(long long)mid<=N){
                  ans=mid;
                  s=mid+1;
              }else{
                  e=mid-1;
              }
          }
          if(ans*(long long)ans!=N)
          return ans;
          else return ans-1;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.countSquares(N) << endl;
    }
    return 0;
}  // } Driver Code Ends