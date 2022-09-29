class Solution {
public:
    unordered_map<string, vector<pair<string, double>>> graph;                               // adjacency list
    
    /*pair<bool, double> search(string& a, string& b, unordered_set<string>& visited, double val) {
        if (visited.count(a) == 0) {
            visited.insert(a);                                                                  // mark a as visited
            for (auto p : children[a]) {
                double temp = val * p.second;                                                   // potential result
                if (p.first == b) { return make_pair(true, temp); }                             // found result
                
                auto result = search(p.first, b, visited, temp);
                if (result.first) { return result; }
            }
        }
        return make_pair(false, -1.0);
    }*/
    
    double dfs(string src, string dest, unordered_set<string> &vis)
    {
        if(graph.find(src)==graph.end()) return -1;
        if(src==dest) return 1;
        for(auto node:graph[src])
        {
            if(vis.find(node.first)!=vis.end()) continue;
            vis.insert(node.first);
            double res=dfs(node.first, dest, vis);
            if(res!=-1)
                return res*node.second;
        }
        return -1;
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> ans;
        
        for(int i=0;i<equations.size();i++)
        {
            graph[equations[i][0]].push_back({equations[i][1], values[i]});
            graph[equations[i][1]].push_back({equations[i][0], 
                                              (double)1.0/values[i]});
        }
        for(int i=0;i<queries.size();i++)
        {
            unordered_set<string> vis;
            ans.push_back(dfs(queries[i][0], queries[i][1], vis));
        }
        return ans;
    }
};