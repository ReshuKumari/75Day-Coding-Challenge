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
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL)
            return NULL;
        queue<TreeNode*> s;
        s.push(root);
        while(s.empty()==false)
        {
            TreeNode* top=s.front();
            s.pop();
            if(top->left!=NULL)
                s.push(top->left);
            if(top->right!=NULL)
                s.push(top->right);
            swap(top->left, top->right);
        }
        return root;
    }
};

//temp=a;
//a=b;
//b=temp;
