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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* n = new TreeNode(val);
            n->left = root;
            return n;
        }
        queue<TreeNode*> q;
        int d=0;
        q.push(root);
        while(!q.empty())
        {
            int size=q.size();
            d++;
            for(int i=0;i<size;i++)
            {
                TreeNode* t=q.front(); q.pop();
                if(d==depth-1)
                {
                    TreeNode* l=(t->left!=NULL)?t->left:NULL;
                    TreeNode* r=(t->right!=NULL)?t->right:NULL;
                    if(l==NULL)
                    {
                        t->left=new TreeNode(val);
                    }
                    else
                    {
                        t->left=new TreeNode(val);
                        t->left->left=l;
                    }
                    if(r==NULL)
                    {
                        t->right=new TreeNode(val);
                    }
                    else
                    {
                        t->right=new TreeNode(val);
                        t->right->right=r;
                    }
                }
                if(t->left!=NULL)
                    q.push(t->left);
                if(t->right!=NULL)
                    q.push(t->right);
            }
            if(d==depth)
            {
                break;
            }
        }
        return root;
    }
};