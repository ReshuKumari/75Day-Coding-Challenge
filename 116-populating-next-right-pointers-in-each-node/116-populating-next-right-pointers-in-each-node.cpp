/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    /*Node* connect(Node* root) {
        if(root==NULL) return root;
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            int n=q.size();
            q.push(NULL);
            for(int i=0;i<n;i++)
            {
                Node* t=q.front(); q.pop();
                Node* a=q.front();
                t->next=a;
                if(t->left!=NULL)
                    q.push(t->left);
                if(t->right!=NULL)
                    q.push(t->right);
            }
            q.pop();
        }
        return root;
    }*/
    Node* connect(Node *root) {
        if(root==NULL)
            return root;
        Node* level_start=root;
        while(level_start!=NULL)
        {
            Node* cur=level_start;
            while(cur!=NULL)
            {
                if(cur->right!=NULL)
                {
                    cur->left->next=cur->right;
                }
                if(cur->right!=NULL && cur->next!=NULL)
                {
                    cur->right->next=cur->next->left;
                }
                cur=cur->next;
            }
            level_start=level_start->left;
        }
        return root;
    }
};