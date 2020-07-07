/*
	Problem URL :- https://practice.geeksforgeeks.org/problems/levelorder-traversal-of-a-bst/1
*/


#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *createNewNode(int value)
{
    Node *temp=new Node;
    temp->data=value;
    temp->left=temp->right=NULL;
    return temp;
}

Node *newNode(Node *root,int data)
{
    if(root==NULL)
    root=createNewNode(data);
    else if(data<root->data)
    root->left=newNode(root->left,data);
    else
    root->right=newNode(root->right,data);
    return root;
    
}


 // } Driver Code Ends
//User function Template for C++

//Complete this function
void levelOrder(Node *root)
{
    if(root==NULL)
    return;
    
    queue<Node *> q;
    q.push(root);
    
    while(q.size()>0) {
        int size = q.size();
        for(int i=0; i<size; i++) {
            Node *temp = q.front();
            q.pop();
            cout<<temp->data<<" ";
            if(temp->left!=NULL) q.push(temp->left);
            if(temp->right!=NULL) q.push(temp->right);
        }
    }
}


// { Driver Code Starts.



int main() {
    
    int testcases;
    cin>>testcases;
    while(testcases--)
    {
        Node *root=NULL;
        int sizeOfArray;
        cin>>sizeOfArray;
        int arr[sizeOfArray];
        
        for(int i=0;i<sizeOfArray;i++)
        cin>>arr[i];
        
        for(int i=0;i<sizeOfArray;i++)
        {
            root=newNode(root,arr[i]);
        }
        
        levelOrder(root);
        cout<<endl;
        
        
    }
	return 0;
}  // } Driver Code Ends
