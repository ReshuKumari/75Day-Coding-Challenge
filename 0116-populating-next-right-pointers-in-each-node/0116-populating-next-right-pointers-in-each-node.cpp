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
    Node* connect(Node *A) {
  if(!A)
    return A;
    queue<Node*> q;
    q.push(A);
    Node* temp;
    while(!q.empty())
    {
        int n = q.size();
        for(int i = 1 ; i <= n ; i++){
            Node * temp = q.front();
            q.pop();
            if(i == n){
                temp->next = NULL;
            }
            else
                temp->next = q.front();
            if(temp->left != nullptr)
                q.push(temp->left);
            if(temp->right != nullptr)
                q.push(temp->right);
        }
    }
    return A;
    }
};