/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int,multiset<int>>> mp;
        queue<pair<TreeNode*, pair<int,int>>> q;
        q.push({root,{0,0}});
        while(!q.empty())
        {
            auto t=q.front();
            q.pop();
            mp[t.second.first][t.second.second].insert(t.first->val); 
            if(t.first->left !=NULL)
            q.push({t.first->left, {t.second.first-1,t.second.second+1}});
            if(t.first->right != NULL)
            q.push({t.first->right, {t.second.first+1, t.second.second+1}});
        }
        vector<vector<int> >ans;
        for(auto a:mp)
        {
            int k=0;
            auto b=a.second;
            vector<int> v;
            for(auto i:b)
            {
                for(auto x: i.second)
                    v.push_back(x);
            }
            ans.push_back(v);
        }
        return ans;
    }
};