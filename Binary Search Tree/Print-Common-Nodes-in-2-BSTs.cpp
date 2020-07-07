/* 
	Problem URL :- https://practice.geeksforgeeks.org/problems/print-common-nodes-in-bst/1
*/
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

void printCommon(Node *root1, Node *root2);

int main()
{
    int t;
    cin>>t;
    getchar();
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root1 = buildTree(s);

        getline(cin,s);
        Node* root2 = buildTree(s);

        printCommon(root1, root2);
        cout<< endl;
    }

	return 1;
}// } Driver Code Ends
/*Node structure

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

/* Function should print common elements in given two trees */

void makeVector(Node *root, vector<int>& list) {
    if(root==NULL) return;
    makeVector(root->left, list);
    list.push_back(root->data);
    makeVector(root->right,list);
}
void printCommon(vector<int> list1,vector<int> list2) {
    int i=0,j=0, size1=list1.size(), size2=list2.size();
    
    while(i<size1 && j<size2) {
        if(list1[i]==list2[j]) {
            cout<<list1[i]<<" ";
            i++;
            j++;
        } else if(list1[i]<list2[j]) {
            i++;
        } else {
            j++;
        }
    }
    
}
void printCommon(Node *root1, Node *root2)
{
     //Your code here
     vector<int> list1,list2;
     makeVector(root1,list1);
     makeVector(root2,list2);
    //  sort(list1.begin(), list1.end());
    //  sort(list2.begin(), list2.end());
     
     printCommon(list1,list2);
}



