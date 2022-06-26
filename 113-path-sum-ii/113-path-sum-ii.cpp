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
    /*bool isLeaf(TreeNode *root)
    {
        return !root->left and !root->right;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        queue<pair<TreeNode*, pair<int, vector<int>>>> q;
        if(!root)
            return ans;
        q.push({root,{root->val, {root->val}}});
        while(!q.empty())
        {
            auto a=q.front(); q.pop();
            TreeNode* cur=a.first;
            int cursum=a.second.first;
            vector<int> curpath=a.second.second;
            if(isLeaf(cur) && targetSum==cursum)
            {
                ans.push_back(curpath);
            }
            if(cur->left!=NULL)
            {
                vector<int> leftpath=curpath;
                leftpath.push_back(cur->left->val);
                q.push({cur->left, {cursum+cur->left->val, leftpath}});
            }
            if(cur->right!=NULL)
            {
                vector<int> rightpath=curpath;
                rightpath.push_back(cur->right->val);
                q.push({cur->right, {cursum+cur->right->val, rightpath}});
            }
        }
        return ans;
        
    }*/
    
    
    
    vector<vector<int>> ans;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        dfs(root, targetSum, path);
        return ans;
    }
    void dfs(TreeNode* root, int targetSum, vector<int>& path) {
        if (root == nullptr) return;
        path.push_back(root->val);
        targetSum -= root->val;
        if (root->left == nullptr && root->right == nullptr) { // Is leaf node
            if (targetSum == 0) // Found valid path
                ans.push_back(path);
        } else {
            dfs(root->left, targetSum, path);
            dfs(root->right, targetSum, path);
        }
        path.pop_back(); // backtrack
    }
};