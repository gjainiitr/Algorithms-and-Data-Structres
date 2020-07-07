// Problem URL :- https://practice.geeksforgeeks.org/problems/intersection-point-in-y-shapped-linked-lists/1

#include<iostream>
#include<stdio.h>
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

int intersectPoint(struct Node* head1, struct Node* head2);

void append(struct Node** head_ref, struct Node **tail_ref, int new_data)
{
    struct Node* new_node = new Node(new_data);
    if (*head_ref == NULL)
        *head_ref = new_node;
    else
        (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}

/* Driver program to test above function*/
int main()
{
    int T,i,n1, n2, n3,l,k;

    cin>>T;
    while(T--)
    {
        cin>>n1>>n2>>n3;

        struct Node *head1 = NULL,  *tail1 = NULL;
        for(i=1; i<=n1; i++)
        {
            cin>>l;
            append(&head1, &tail1, l);
        }
        struct Node *head2 = NULL,  *tail2 = NULL;
        for(i=1; i<=n2; i++)
        {
            cin>>l;
            append(&head2, &tail2, l);
        }
        struct Node *head3 = NULL,  *tail3 = NULL;
        for(i=1; i<=n3; i++)
        {
            cin>>l;
            append(&head3, &tail3, l);
        }

        if (tail1 != NULL)
        tail1->next = head3;
        if (tail2 != NULL)
        tail2->next = head3;

        cout << intersectPoint(head1, head2) << endl;
    }
    return 0;
}

// } Driver Code Ends
/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

/* Should return data of intersection point of two linked
   lists head1 and head2.
   If there is no intersecting point, then return -1. */
int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
    int l1Length=1, l2Length=1;
    Node *temp;
    int x;
    
    temp=head1;
    while(temp->next!=NULL) {
        temp=temp->next;
        l1Length+=1;
    }
    temp=head2;
    while(temp->next!=NULL) {
        temp=temp->next;
        l2Length+=1;
    }
    
    if(l1Length<l2Length) {
        temp = head2;
        head2 = head1;
        head1 = temp;
        x = l1Length;
        l1Length = l2Length;
        l2Length = x;
    }
    
    x = l1Length-l2Length;
    Node *node1=head1, *node2=head2;
    for(int i=0; i<x; i++) node1=node1->next;
    
    while(node1!=NULL) {
        if(node1==node2) return node1->data;
        else {
            node1=node1->next;
            node2=node2->next;
        }
    }
}


