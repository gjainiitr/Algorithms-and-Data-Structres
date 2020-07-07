// Problem URL :- https://practice.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* addTwoLists(struct Node* first, struct Node* second);

void push(struct Node** head_ref, int new_data) {
    struct Node* new_Node = new Node(new_data);
    new_Node->next = (*head_ref);
    (*head_ref) = new_Node;
}
void printList(struct Node* Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}
void freeList(struct Node* Node) {
    struct Node* temp;
    while (Node != NULL) {
        temp = Node;
        Node = Node->next;
        free(temp);
    }
}
int main(void) {
    int t, n, m, i, x;
    cin >> t;
    while (t--) {
        struct Node* res = NULL;
        struct Node* first = NULL;
        struct Node* second = NULL;
        cin >> n;
        for (i = 0; i < n; i++) {
            cin >> x;
            push(&first, x);
        }
        cin >> m;
        for (i = 0; i < m; i++) {
            cin >> x;
            push(&second, x);
        }
        res = addTwoLists(first, second);
        printList(res);
        if (first) freeList(first);
        if (second) freeList(second);
    }
    return 0;
}
// } Driver Code Ends

/*
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/
// write a function returns the resultant linked list
Node* addTwoLists(Node* first, Node* second) {
    // Code here
    if(first==NULL) return second;
    if(second==NULL) return first;
    int carry=0,sum=0;
    Node *head=new Node(0);
    Node *temp=head;
    while(first!=NULL && second!=NULL) {
        //calculate sum and carry
        sum=(first->data) + (second->data) + carry;
        if(sum>9) {carry=1; sum-=10; } else carry=0;
        temp->next = new Node(sum);
        temp=temp->next;
        first=first->next; second=second->next;
    }
    while(first!=NULL) {
        sum = carry + first->data;
        if(sum>9) {carry=1; sum-=10; } else carry=0;
        temp->next = new Node(sum);
        temp = temp->next;
        first=first->next;
        
    }
    while(second!=NULL) {
        sum = carry + second->data;
        if(sum>9) {carry=1; sum-=10; } else carry=0;
        temp->next = new Node(sum);
        temp = temp->next;
        second=second->next;
    }
    if(carry == 1) {
        temp->next = new Node(1);
        temp=temp->next;
    }
    temp = head->next;
    delete(head);
    return temp;
}
