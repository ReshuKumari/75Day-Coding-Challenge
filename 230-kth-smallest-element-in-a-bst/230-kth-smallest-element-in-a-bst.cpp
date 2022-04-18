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
    int kthSmallest(TreeNode* root, int &k) {
        if(!root) return INT_MIN;
        int l = kthSmallest(root->left,k);
        if(k == 0) return l;
        else if(k == 1){
            k--;
            return root->val;
        }
        else{
            k--;
            int r = kthSmallest(root->right,k);
            if(k==0) return r;
            else return INT_MIN;   
        }
    }
};