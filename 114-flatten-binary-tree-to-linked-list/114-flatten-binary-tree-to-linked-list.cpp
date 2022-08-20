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
    void flatten(TreeNode* root) {
        if(root==NULL)
            return;
        while(root!=NULL)
        {
            if(root->left!=NULL)
            {
                TreeNode* left=root->left;
                TreeNode* curr=left;
                while(curr->right!=NULL)
                {
                    curr=curr->right;
                }
                curr->right=root->right;
                root->left=NULL;
                root->right=left;
            }
            root=root->right;
        }
        return;
    }
};