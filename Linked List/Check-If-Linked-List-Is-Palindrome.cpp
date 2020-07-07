// Problem URL :- https://practice.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

void append(struct Node** head_ref, struct Node **tail_ref, int new_data)
{
    struct Node* new_node = new Node(new_data);
    
    if (*head_ref == NULL)
       *head_ref = new_node;
    else
       (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}


bool isPalindrome(Node *head);
/* Driver program to test above function*/
int main()
{
  int T,i,n,l;
    cin>>T;
    while(T--){
    struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        for(i=1;i<=n;i++)
        {
            cin>>l;
            append(&head, &tail, l);
        }
   	cout<<isPalindrome(head)<<endl;
    }
    return 0;
}

// } Driver Code Ends

/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
bool isPalindrome(Node *head) {
	struct Node *p;
	p=head;
	int t1=0,t2=0,n=1;
	while(p!=NULL) {
		t1=t1+(p->data*n);
		t2=(t2*10)+p->data;
		p=p->next;
		n=n*10;
	}
	if(t1==t2) {		
		return 1;	
	} else {
		return 0;
	}
}
