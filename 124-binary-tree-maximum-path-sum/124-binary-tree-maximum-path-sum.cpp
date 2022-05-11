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
    int maxPathSum(TreeNode* root) {
        int maxsum=INT_MIN;
        maxpathsum(root, maxsum);
        return maxsum;
    }
    int maxpathsum(TreeNode* root, int &maxsum)
    {
        if(root==NULL)
            return 0;
        int l=max(maxpathsum(root->left,maxsum),0);
        int r=max(maxpathsum(root->right, maxsum),0);
        int sum=root->val+l+r;
        maxsum=max({sum, maxsum});
        return root->val+max(l,r);
    }
};