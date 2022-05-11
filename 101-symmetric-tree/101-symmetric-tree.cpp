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
    
    /*bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        queue<pair<TreeNode*, TreeNode*>> q;
        q.push(make_pair(root->left, root->right));
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            if(!p.first && !p.second) continue;
            if(!p.first || !p.second) return false;
            if(p.first->val != p.second->val) return false;
            q.push(make_pair(p.first->left, p.second->right));
            q.push(make_pair(p.first->right, p.second->left));
        }
        return true;
    }*/
    bool isSymmetric(TreeNode* root) {
        if(root==nullptr)  return true;
        return isSymmetric(root->left, root->right);
    }
    
    bool isSymmetric(TreeNode* left, TreeNode* right){
        if(left==nullptr && right==nullptr)   return true;
        if(left==nullptr || right==nullptr || left->val!=right->val)    
            return false;
        return isSymmetric(left->left, right->right) && 
            isSymmetric(right->left, left->right);
    }
};