/*
	Problem URL :- https://practice.geeksforgeeks.org/problems/delete-a-node-from-bst/1
*/
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

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



struct Node* deleteNode(struct Node* root, int key);

// Function to Build Tree
Node* buildTree(string str)
{
   // Corner Case
   if(str.length() == 0 || str[0] == 'N')
       return NULL;

   // Creating vector of strings from input
   // string after spliting by space
   vector<string> ip;

   istringstream iss(str);
   for(string str; iss >> str; )
       ip.push_back(str);

   // Create the root of the tree
   Node* root = newNode(stoi(ip[0]));

   // Push the root to the queue
   queue<Node*> queue;
   queue.push(root);

   // Starting from the second element
   int i = 1;
   while(!queue.empty() && i < ip.size()) {

       // Get and remove the front of the queue
       Node* currNode = queue.front();
       queue.pop();

       // Get the current node's value from the string
       string currVal = ip[i];

       // If the left child is not null
       if(currVal != "N") {

           // Create the left child for the current node
           currNode->left = newNode(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->left);
       }

       // For the right child
       i++;
       if(i >= ip.size())
           break;
       currVal = ip[i];

       // If the right child is not null
       if(currVal != "N") {

           // Create the right child for the current node
           currNode->right = newNode(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->right);
       }
       i++;
   }

   return root;
}

void inorder(Node *root, vector<int> &v)
{
    if(root==NULL)
        return;

    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

int main() {
   
   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   while(t--)
   {
    string s; 
    getline(cin, s);
    Node* root1 = buildTree(s);
    getline(cin, s);
    int k = stoi(s);
    root1  = deleteNode(root1, k);
    vector<int> v;
    inorder(root1, v);
    for(auto i:v)
        cout << i << " ";
    cout << endl;
   }
   return 0;
}// } Driver Code Ends
/* The structure of a BST Node is as follows:
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
void adjust(Node *& left, Node *& right) {
    if(right==NULL) {
        right=left;
        return;
    }
    
    if(right->left==NULL) {
        right->left = left;
        return;
    } else {
        adjust(left, right->left);
    }
}
void deleteX(Node *& root, int x) {
    if(root->left==NULL && root->right==NULL) return;
    
    if(x < root->data) { // clearly x is on the left side of the root
        if(root->left==NULL) return; // x not found
        if(root->left->data == x) {
            Node *left = root->left->left;
            Node *right = root->left->right;
            delete(root->left);
            adjust(left, right);
            root->left = right;
            return;
        } else {
            deleteX(root->left, x);
        }
    } else if (x > root->data) {
        if(root->right==NULL) return;
        if(root->right->data==x) {
            Node *left = root->right->left;
            Node *right = root->right->right;
            delete(root->right);
            adjust(left,right);
            root->right = right;
            return;
        } else {
            deleteX(root->right, x);
        }
    }
    
}
Node *deleteNode(Node *root,  int x)
{
    // your code goes here
    if(root==NULL) return root;
    
    
    if(root->data == x) {
        Node *left = root->left;
        Node *right = root->right;
        delete(root);
        adjust(left,right);
        return right;
    }
    
    
    // root->data != x
    
    deleteX(root,x);
    return root;
}

