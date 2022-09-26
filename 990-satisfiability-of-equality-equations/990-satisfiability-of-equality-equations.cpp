class Solution {
    vector<bool> visited;
    vector<int> color;
    vector<vector<int>> adj;
    
    public:
    void dfsVisit(int u, int colorNumber)
    {
        visited[u]=true;
        color[u]=colorNumber;
        for(auto v: adj[u])
        {
            if(!visited[v])
                dfsVisit(v, colorNumber);
        }
    }
    bool equationsPossible(vector<string> &equations)
    {
        int alphabetsize=26;
        adj.resize(alphabetsize);
        color.resize(alphabetsize);
        visited.resize(alphabetsize);
        for(auto str: equations)
        {
            if(str[1]=='=')
            {
                char firstletter=str[0], secondletter=str[3];
                adj[firstletter-'a'].push_back(secondletter-'a');
                adj[secondletter-'a'].push_back(firstletter-'a');
            }
        }
        int colorNumber=0;
        for(int u=0;u<alphabetsize;u++)
        {
            if(!visited[u])
                dfsVisit(u, colorNumber);
            colorNumber++;
        }
        for(auto str: equations)
        {
            if(str[1]=='!')
            {
                char firstletter  = str[0];
                char secondletter = str[3];
                if(color[firstletter-'a']==color[secondletter-'a'])
                    return false;
            }
        }
        return true;
    }
};