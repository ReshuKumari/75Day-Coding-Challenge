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
    //inorder ==> LPR
    /*vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> s;
        while(root->left && root->right)
        {
            s.push(root);
            if(root->left!=NULL)
            {
                root=root->left;
            }
            if(root->right!=NULL)
            {
                root=root->right;
            }
            ans.push_back(root->val);
        }
        return ans;
    }*/
    
    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int> ans;
        while(root)
        {
            if(root->left!=NULL)
            {
                TreeNode *pre=root->left;
                while(pre->right && pre->right!=root)
                {
                    pre=pre->right;
                }
                if(!pre->right)
                {
                    pre->right=root;
                    root=root->left;
                }
                else
                {
                    pre->right=NULL;
                    ans.push_back(root->val);
                    root=root->right;
                }
            }
            else
            {
                ans.push_back(root->val);
                root=root->right;
            }
        }
        return ans;
    }
};