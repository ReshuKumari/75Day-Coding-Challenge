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
        if(root == NULL){
        return 0;
    }
    int leftBS = root->val + maxpathsum( root->left , maxsum );
    int rightBS = root->val + maxpathsum( root->right ,  maxsum);
    maxsum = max({
                maxsum,            
                root->val,  
                leftBS,
                rightBS, 
                leftBS + rightBS - root->val  
            });
    return max({ leftBS , rightBS , root->val });
    }
};