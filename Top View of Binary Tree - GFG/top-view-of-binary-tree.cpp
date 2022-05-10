// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends


/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //Your code here
         /*map<int,int> v;

        vector<int> a;
        if(!root) return a;
        queue<pair<Node*,int>> q;
        q.push({root,0});
 
        while(q.size()){
            Node *t = q.front().first;
            int vh = q.front().second;
            q.pop();
            
			 // if this column index already has a 
		    //node we dont need to change it 
            if(v[vh]==0) v[vh]=t->data;   
			
            if(t->left) q.push({t->left,vh-1});
            if(t->right) q.push({t->right,vh+1});

        }
		
      // all the nodes in the map are the nodes which are 
	  // encountered first in the verical traversal so  gives us the top view of the tree
        
        for(auto x:v) a.push_back(x.second);    
        return a;*/
        
        
        // Your Code Here
        map<int, int> mp;
        queue<pair<Node*, int>> q;
        q.push({root,0});
        while(!q.empty())
        {
            auto t=q.front();
            q.pop();
            if(mp.find(t.second)==mp.end())
            mp[t.second]=t.first->data;
            if(t.first->left !=NULL)
            q.push({t.first->left, t.second-1});
            if(t.first->right != NULL)
            q.push({t.first->right, t.second+1});
        }
        vector<int> ans;
        for(auto a:mp)
        {
            ans.push_back(a.second);
        }
        return ans;
    }

};



// { Driver Code Starts.

int main() {
    int tc;
    cin>>tc;
    cin.ignore(256, '\n');
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node *root = buildTree(treeString);
        vector<int> vec = ob.topView(root);
        for(int x : vec)
            cout<<x<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends