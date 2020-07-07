/*
	Problem URL :- https://practice.geeksforgeeks.org/problems/implementing-ceil-in-bst/1
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

/* This function is used to insert 
new values in BST*/
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

//User function Template for C++

/*
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

// Function to find ceil of a given input in BST. If input is more 
// than the max key in BST, return -1 
void ceiling(Node* root, int key, int& res) {
    if(root==NULL) return;
    int data = root->data;
    
    if(data==key) {
        res=key;
        return;
    }
    if(data<key) {
        ceiling(root->right, key, res);
    }
    if(data>key) {
        res = min(res, data);
        ceiling(root->left, key, res);
    }
}
int findCeil(Node* root, int input) 
{ 
    // Base case 
    if (root == NULL) 
        return -1; 
    
    int res = INT_MAX;
    ceiling(root,input,res);
    if(res==INT_MAX) return -1;
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
	    cout << findCeil(root, x) << endl;
	}
	
	return 0; 
}  // } Driver Code Ends
