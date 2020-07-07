/*
	Problem URL :- https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1
*/
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};

void topView(struct Node *root);


int main()
{
    int t;cin>>t;
    while(t--)
    {
        int n,i,k;
        cin>>n;
        i=n;

        Node* root=NULL;
        queue <Node*> q;
        while(i>0)
        {
            int a,b;
            char c;
            cin>> a >> b >> c;
            if(!root){
                root = new Node(a);
                q.push(root);
            }
            Node* pick = q.front();
            q.pop();

            if(c == 'L'){
                pick->left = new Node(b);
                q.push( pick->left );
            }
            cin>> a >> b >> c;
            if(c == 'R'){
                pick->right = new Node(b);
                q.push( pick->right );
            }
            i-=2;
        }
//        inorder(root);
//        cout<<endl;
        topView(root);
        cout << endl;
    }
    return 0;
}




// } Driver Code Ends
//Structure of binary tree
/*struct Node
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
// function should print the topView of the binary tree

void topView(struct Node *root)
{
    //Your code here
    map<int, int> m;
    
    pair<Node *, int> p(root, 0);
    queue<pair<Node *, int>> q;
    q.push(p);
    
    while(q.size()>0) {
        int size = q.size();   
        for(int i=0; i<size; i++) {
           
            pair<Node *, int> temp = q.front();
            q.pop();
 
            // main code here
            if(m.find(temp.second)==m.end()) {
                m[temp.second] = temp.first->data;        
            }
    
    
            if(temp.first->left!=NULL) {
                pair<Node *, int> temp1(temp.first->left, temp.second-1);
                q.push(temp1);
            }
            if(temp.first->right!=NULL) {
                pair<Node *, int> temp2(temp.first->right, temp.second+1); 
                q.push(temp2);
            }
        }
    }
    for(auto it=m.begin(); it!=m.end(); it++) {
        cout<<it->second<<" ";
    }
}



