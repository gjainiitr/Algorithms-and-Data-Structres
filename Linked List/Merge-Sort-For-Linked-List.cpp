// Problem URL :- https://practice.geeksforgeeks.org/problems/sort-a-linked-list/1

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


 // } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/

/* Function to mergesort the linked list
   It should return head of the modified list  */
Node* merge(Node* start1, Node* start2) {
    if(start1==NULL) return start2;
    if(start2==NULL) return start1;
    Node *temp1=start1, *temp2=start2;
    Node *head, *headPointer;
    if(temp1->data <= temp2->data) {
        head=temp1; headPointer=start1; temp1=temp1->next;
    } else {
        head=temp2; headPointer=start2; temp2=temp2->next;
    }
    while(temp1!=NULL && temp2!=NULL) {
        if(temp1->data <= temp2->data) {
            head->next = temp1;
            head=head->next;
            temp1=temp1->next;
        } else {
            head->next = temp2;
            head=head->next;
            temp2=temp2->next;
        }
    }
    while(temp1!=NULL) {
        head->next = temp1;
        head=head->next;
        temp1=temp1->next;
    }
    while(temp2!=NULL) {
        head->next = temp2;
        head=head->next;
        temp2=temp2->next;
    }
    return headPointer;
}
Node* mergeSort(Node* head) {
    // your code here
    int count=1; Node *temp=head;
    if(head==NULL || head->next==NULL) return head;
    while(temp!=NULL) {
        count++;
        temp=temp->next;
    }
    temp=head;
    for(int i=0; i<count/2-1; i++) temp=temp->next;
    Node* next=temp->next;
    temp->next=NULL;
    head = mergeSort(head);
    next = mergeSort(next);
    merge(head, next);
}


// { Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        a = mergeSort(a);
        printList(a);
    }
    return 0;
}  // } Driver Code Ends
