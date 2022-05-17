/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node==NULL)
            return NULL;
        map<Node*, Node*> mp;
        mp[node]=new Node(node->val);
        queue<Node*> q;
        q.push(node);
        while(!q.empty())
        {
            Node* t=q.front();
            q.pop();
            for(auto nbr:t->neighbors)
            {
                if(mp.count(nbr)==0)
                {
                    mp[nbr]=new Node(nbr->val);
                    q.push(nbr);
                }
                mp[t]->neighbors.push_back(mp[nbr]);
            }
        }
        return mp[node];
    }
};