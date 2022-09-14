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
    int ans=0;
    unordered_map<int, int> mp;
    void dfs(TreeNode* root)
    {
        if(root==NULL)
        {    return; }
        mp[root->val]++;
        if(root->left==NULL && root->right==NULL)
        {
            int val=0;
            for(auto a:mp)
            {
                if(a.second%2==1)
                {
                    val++;
                    if(val==2)
                    {
                        break;
                    }
                }
                
            }
            if(val<=1)
            {    ans++; }
        }
        dfs(root->left);
        dfs(root->right);
        mp[root->val]--;
        return;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        dfs(root);
        return ans;
    }
};