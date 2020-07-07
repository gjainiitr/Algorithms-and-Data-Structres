/*
	Problem URL :- https://practice.geeksforgeeks.org/problems/children-sum-parent/1
*/

#include <bits/stdc++.h>

using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

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
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

int isSumProperty(struct Node *node);

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string str;
        getline(cin, str);
        Node *root = buildTree(str);
        cout << isSumProperty(root) << "\n";

        
    }


    return 0;
}// } Driver Code Ends
/*Complete the function below

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/
// int parentSum(Node *node) {
//     if(node==NULL) return 0;
    
//     int lSum = parentSum(node->left);
//     if(lSum==-1) return -1;
//     int rSum = parentSum(node->right);
//     if(rSum==-1) return -1;
    
//     if(node->left==NULL && node->right==NULL) return node->data;
//     if(node->data != (lSum+rSum)) return -1;
//     return (node->data);
// }
int isSumProperty(Node *node)
{
 // Add your code here
    if(node==NULL) return 1;
    if(node->left==NULL && node->right==NULL) return 1;
    
    int lSum = isSumProperty(node->left);
    if(lSum==0) return 0;
    if(node->left!=NULL) lSum = node->left->data;
    else lSum=0;
    
    int rSum = isSumProperty(node->right);
    if(rSum==0) return 0;
    if(node->right!=NULL) rSum = node->right->data;
    else rSum=0;
    
    int temp;
    if(node->data == lSum + rSum) temp=1;
    else temp=0;
    
    return temp;
}
