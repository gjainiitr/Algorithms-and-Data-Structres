// Problem URL :- https://practice.geeksforgeeks.org/problems/tree-from-postorder-and-inorder/1
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}

Node* buildTree(int in[], int post[], int n);

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Node* root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/
int find(int in[], int n, int temp) {
    // int temp = post[postIndex];
    for(int i=0; i<n; i++) {
        if(in[i]==temp) return i;
    }
}
void createNode(int post[],int n, int in[], int &postIndex, int start, int end, Node *&curr) {
    curr = new Node(post[postIndex]);
    int i = find(in,n,post[postIndex]);
    postIndex--;
    if(postIndex<0) return;
    if(i+1<=end) {
        createNode(post,n,in,postIndex,i+1,end,curr->right);
    }
    if(start<=(i-1)) {
        createNode(post,n,in,postIndex,start,i-1,curr->left);
    }
}

Node *buildTree(int in[], int post[], int n) {
    // Your code here
    if(n==0) return NULL;
    if(n==1) return new Node(in[0]);
    

    Node *root;
    int postIndex=n-1;
    createNode(post,n,in,postIndex,0,n-1,root);
    
    return root;
}

