/*
	Problem URL :- https://practice.geeksforgeeks.org/problems/implementing-floor-in-bst/1
*/
//Initial Template for C++
// CPP code to find floor of a key in BST 
#include <bits/stdc++.h> 
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

Node* insert(Node* root, int key) 
{ 
	if (!root) 
		return new Node(key); 
	if (key < root->data) 
		root->left = insert(root->left, key); 
	else
		root->right = insert(root->right, key); 
	return root; 
} 



 // } Driver Code Ends

// Make use of BST Properties
void findFloor(Node *root, int key, int& res) {
    if(root==NULL) return;
    
    int data = root->data;
    if(data==key) {
        res=key;
        return;
    }
    
    if(key < data) {
        findFloor(root->left,key,res);
    }
    
    if(data < key) {
        res = max(res, data);
        findFloor(root->right,key,res);
    }
}
int floor(Node* root, int key) 
{ 
	if (root==NULL) 
		return INT_MAX; 

    int res = 0;
    findFloor(root,key,res);
	// Your code here
    if(res==0) return INT_MAX;
    else return res;
}



// { Driver Code Starts.

int main() 
{ 
	
	int t;
	cin >> t;
	while(t--){
	    Node* root = NULL;
	    int n, x;
	    cin >> n;
	    int arr[n];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr[i];
	        if(root == NULL) root = insert(root, arr[i]);
	        else insert(root, arr[i]);
	    }
	    cin >> x;
	    cout << floor(root, x) << endl; 
	}
	
	return 0; 
}  // } Driver Code Ends
