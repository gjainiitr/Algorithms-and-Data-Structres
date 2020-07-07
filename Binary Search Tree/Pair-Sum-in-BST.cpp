/*
	Problem URL :- https://practice.geeksforgeeks.org/problems/pair-sum-in-bst/1
*/
// Initial Template for C++

// CPP program to find a pair with
// given sum using hashing
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *left, *right;
    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

Node* insert(Node* root, int key) {
    if (root == NULL) return new Node(key);
    if (key < root->data)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);
    return root;
}


bool findPair(Node* root, int sum);

// Driver code
int main() {

    int t;
    cin >> t;
    while (t--) {
        Node* root = NULL;
        int n, x;
        cin >> n;
        int val;
        for (int i = 0; i < n; i++) {
            cin >> val;
            root = insert(root, val);
        }
        cin >> x;
        if (findPair(root, x))
            cout << "1" << endl;
        else
            cout << "0" << endl;
    }

    return 0;
}// } Driver Code Ends
/* BST Node
struct Node {
    int data;
    struct Node *left, *right;
    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
*/

// This function should return true
// if there is a pair in given BST with
// given sum.

void addSet(Node *root, unordered_set<int>& s) {
    if(root==NULL) return;
    addSet(root->left,s);
    s.insert(root->data);
    addSet(root->right,s);
}

void checkData(Node *root, unordered_set<int>& s, int sum, bool& res) {
    if(root==NULL) return;
    checkData(root->left, s, sum ,res);
    
    int data = root->data;
    if(sum<=data) return;
    
    if(s.find(sum-data)!=s.end()) {
        res = true;
        return;
    } else {
        s.insert(data);
    }
    
    checkData(root->right, s, sum ,res);
}

bool findPair(Node* root, int sum) {
    // Your code here
    if(root==NULL) return false;
    
    unordered_set<int> s;
    // addSet(root,s);

    bool res = false;
    checkData(root,s,sum,res);

    return res;
}
