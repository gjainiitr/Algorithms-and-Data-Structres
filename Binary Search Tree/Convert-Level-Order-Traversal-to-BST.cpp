/*
	Problem URL :- https://practice.geeksforgeeks.org/problems/convert-level-order-traversal-to-bst/1
*/
#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};

void preorderTraversal(Node* root)
{
	if (!root)return;
	cout << root->data << " ";
	preorderTraversal(root->left);
	preorderTraversal(root->right); 
}

Node* constructBst(int arr[], int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)cin>>arr[i];
        Node *root = constructBst(arr, n);
        preorderTraversal(root);
        cout<<endl;
    }
	return 0; 
}// } Driver Code Ends
//User function Template for C++
/*
Structure of the Node of the node of the bst 
should be as
struct Node {
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};
*/
// You are required to complete this function
struct NodeDetails {
    Node* node;
    int min;
    int max;
    NodeDetails(Node *root,int mini,int maxi) {
        node = root;
        min = mini;
        max = maxi;
    }
};

Node* constructBst(int arr[], int n)
{
    int i=0;
    queue<NodeDetails> q;
    Node *root = new Node(arr[i]);
    i++;
    NodeDetails first(root, INT_MIN, INT_MAX);
    q.push(first);
    
    while(q.size()>0) {
        int size = q.size();
        for(int j=0; j<size; j++) {
            if(i==n) break;
            NodeDetails temp = q.front();
            q.pop();
            
            if(temp.min<arr[i] && arr[i]<temp.node->data) { // make arr[i] the left child and push to the queue
                Node *leftNode = new Node(arr[i]);
                temp.node->left = leftNode;
                NodeDetails left(leftNode, temp.min, temp.node->data);
                q.push(left);
                i++;
            }
        
            if(temp.node->data<arr[i] && arr[i]<temp.max) {
                Node *rightNode = new Node(arr[i]);
                temp.node->right = rightNode;
                NodeDetails right(rightNode, temp.node->data, temp.max);
                q.push(right);
                i++;
            }
        }
        if(i==n) break;
    }

    return root;
}

