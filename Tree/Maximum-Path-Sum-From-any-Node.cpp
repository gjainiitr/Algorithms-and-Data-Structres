// Problem URL :- https://practice.geeksforgeeks.org/problems/maximum-path-sum-from-any-node/1


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

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
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

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
// This function should returns sum of


// All assuming at least one element is positive;
int max2(int a, int b) {
    if(a>b) return a;
    return b;
}
int max4(int a, int b, int c, int d) {
    a = a>b?a:b;
    c = c>d?c:d;
    a = a>c?a:c;
    return a;
}
int findMax(Node *root, int& res, int& maxEach) {
   if(root==NULL) return 0;
   int lsum = findMax(root->left, res, maxEach);
   if(lsum<0) lsum=0;
   int rsum = findMax(root->right, res, maxEach);
   if(rsum<0) rsum=0;
   int data = root->data;
   
   maxEach = max2(data,maxEach); 
   
   res = max4(lsum,rsum,lsum+rsum+data,res);
   return(data + max2(lsum,rsum));
}

int findMaxSum(Node* root)
{
    // Your code goes here
    int res=root->data;
    int maxEach = INT_MIN;
    findMax(root,res,maxEach);
    
    if(maxEach<0) return maxEach;
    return res;
}
// work around no.1 - Have an allnegative boolean variable and find max of each element also, if all elements are -ve 

// { Driver Code Starts.


int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        cout << findMaxSum(root) << "\n";

    }


    return 0;
}  // } Driver Code Ends
