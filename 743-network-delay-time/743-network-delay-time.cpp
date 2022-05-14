class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> vis(n+1,0);
        vector<vector<pair<int,int>>> graph(n+1);
        for(auto t:times)
        {
            graph[t[0]].push_back({t[1], t[2]});
        }
        vis[k]=1;
        vector<int> dist(n+1,INT_MAX);
        dist[k]=0;
        priority_queue<pair<int, int>, vector<pair<int, int>>,greater<pair<int, int>>> pq;
        pq.push({0,k});
        while(!pq.empty())
        {
            pair<int, int> top=pq.top();
            pq.pop();
            int node=top.second;
            for(auto i:graph[node])
            {
                int dest=i.first,weight=i.second;
                if(dist[node]+weight<dist[dest])
                {
                    dist[dest]=dist[node]+weight;
                    vis[dest]=1;
                    pq.push({dist[dest], dest});
                }
            }
        }
        int ans=*max_element(dist.begin()+1, dist.end());
        return ans==INT_MAX?-1:ans;
    }
};