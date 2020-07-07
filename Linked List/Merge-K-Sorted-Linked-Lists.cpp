// Problem URL :- https://practice.geeksforgeeks.org/problems/merge-k-sorted-linked-lists/1

// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

Node* mergeKLists(Node* arr[], int N);

/* Function to print nodes in a given linked list */
void printList(Node* node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	cout<<endl;
}

// Driver program to test above functions
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
	   int N;
	   cin>>N;
       struct Node *arr[N];
       for(int j=0;j<N;j++)
        {
           int n;
           cin>>n;

           int x;
           cin>>x;
           arr[j]=new Node(x);
           Node *curr = arr[j];
           n--;

           for(int i=0;i<n;i++)
           {
               cin>>x;
               Node *temp = new Node(x);
               curr->next =temp;
               curr=temp;
           }
   		}

   		Node *res = mergeKLists(arr,N);
		printList(res);

   }

	return 0;
}
// } Driver Code Ends
/*Linked list Node structure

struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
*/ 

/* arr[] is an array of pointers to heads of linked lists
  and N is size of arr[]  */
Node *merge(Node *l1, Node *l2) {
    if(l1==NULL) return l2;
    if(l2==NULL) return l1;
    
    while(l1!=NULL && l2!=NULL) {
        if(l1->data < l2->data) {
            l1->next = merge(l1->next, l2);
            return l1;
        } else {
            l2->next = merge(l1, l2->next);
            return l2;
        }
    }
}
Node *mergeLists(Node *arr[], int l, int h) {
    if(l==h) return arr[l];
    int mid=l+(h-l)/2;
    Node* l1,*l2;
    l1 = mergeLists(arr,l,mid);
    l2 = mergeLists(arr,mid+1,h);
    
    return merge(l1,l2);
}


Node * mergeKLists(Node *arr[], int N) {
    return mergeLists(arr,0,N-1);
}


