// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    pair<int,int> dfs(int index, vector<pair<int,int>> adj[], int mini)
    {
        if(adj[index].size()==0)
        return {index,mini};
        else
        {
            for(int i=0; i<adj[index].size(); i++)
            {
                if(adj[index][i].second< mini)
                mini=adj[index][i].second;
                
                return dfs(adj[index][i].first,adj,mini);
            }
        }
    }
    vector<vector<int>> solve(int n,int p,vector<int> a,vector<int> b,vector<int> d)
    {
        // code here
        vector<pair<int, int>> graph[n+1];
        vector<int> vis(n+1, 1);
        for(int i=0;i<p;i++)
        {
            graph[a[i]].push_back({b[i], d[i]});
            vis[b[i]]=0;
        }
        vector<vector<int>> ans;
        for(int i=1;i<=n;i++)
        {
            if(vis[i])
            {
                if(graph[i].size()==0) continue;
                vector<int> v;
                int x=INT_MAX;
                pair<int, int> p=dfs(i, graph, x);
                v.push_back(i);
                v.push_back(p.first);
                v.push_back(p.second);
                ans.push_back(v);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};


// { Driver Code Starts.
int main()
{
	int t,n,p;
	cin>>t;
	while(t--)
    {
        cin>>n>>p;
        vector<int> a(p),b(p),d(p);
        for(int i=0;i<p;i++){
            cin>>a[i]>>b[i]>>d[i];
        }
        Solution obj;
        vector<vector<int>> answer = obj.solve(n,p,a,b,d);
        cout<<answer.size()<<endl;
        for(auto i:answer)
        {
            cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<endl;
        }
        
    }
	return 0;
}  // } Driver Code Ends