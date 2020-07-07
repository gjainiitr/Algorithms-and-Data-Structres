/*
	Problem URL :- https://practice.geeksforgeeks.org/problems/preorder-to-postorder/0
*/
#include<stack>
using namespace std;
struct Node {
    int data;
    Node *left;
    Node *right;
    Node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};
void preToTree(int arr[], int start, int end,Node *& root) {
    stack<Node *> s;
    int i=start;
    root = new Node(arr[i]);
    s.push(root);
    i++;
    while(s.size()>0) {
        if(i>end) return;
        while(arr[i]<s.top()->data) {
            if(i>end) return;
            Node *left = new Node(arr[i]);
            s.top()->left = left;
            i++;
            s.push(left);
        }
        Node *temp=NULL;
        while(s.size()>0 && arr[i]>s.top()->data) {
            if(i>end) return;
            temp = s.top();
            s.pop();
            if(s.size()==0 || s.top()->data>arr[i]) {
                Node *right = new Node(arr[i]);
                i++;
                temp->right = right;
                s.push(right);
            }
            
        }
    }
}
void printTreePost (Node *root) {
    if(root==NULL) return;
    printTreePost(root->left);
    printTreePost(root->right);
    cout<<root->data<<" ";
}
int main() {
	//code
	int t;
	cin>>t;
	for(int p=0; p<t; p++) {
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int j=0; j<n; j++) {
	        cin>>arr[j];
	    }
	    Node *root;
	    preToTree(arr,0,n-1,root);
	    printTreePost(root);
	    cout<<endl;
	}
	return 0;
}
