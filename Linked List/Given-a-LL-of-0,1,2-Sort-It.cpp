// Problem URL :- https://practice.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1

#include <bits/stdc++.h>

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

struct Node *start = NULL;

struct Node* segregate(struct Node *head);

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        struct Node *newHead = segregate(start);
        printList(newHead);
    }

    return 0;
}// } Driver Code Ends
/*
  Sort the list of 0's,1's and 2's
  The input list will have at least one element
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

// This function is to segregate the elememtns in the linked list
// This will do the required arrangement by changing the links
Node* segregate(Node *head) {
    
    // Add code here
    int count1=0, count2=0, count3=0;
    if(head==NULL || head->next==NULL) return head;
    Node *oneD=NULL, *twoD=NULL, *threeD=NULL;
    Node *one=NULL, *two=NULL, *three=NULL;
    while(head!=NULL) {
        if(head->data==0) {
            if(one==NULL) {
                one=head;
                oneD=one;
            } else {
                one->next = head;
                one=one->next;
            }
            count1++;
        } else if(head->data==1) {
            if(two==NULL) {
                two=head;
                twoD=two;
            } else {
                two->next = head;
                two=two->next;
            }
            count2++;
        } else if(head->data==2) {
            if(three==NULL) {
                three=head;
                threeD=three;
            } else {
                three->next = head;
                three=three->next;
            }
            count3++;
        }
        head = head->next;
    }
    // one->next=NULL; two->next=NULL; three->next=NULL;
    if(count1==0) {
        if(count2==0) {
            three->next=NULL;
            return threeD;
        }
        if(count3==0) {
            two->next=NULL;
            return twoD;
        }
        two->next=threeD;
        three->next=NULL;
        return twoD;
    }
    if(count2==0) {
        if(count3==0) {
            one->next=NULL;
            return oneD;
        }
        one->next=threeD;
        three->next=NULL;
        return oneD;
    }
    one->next = twoD;
    if(count3==0) {
        two->next=NULL;
    } else {
        two->next=threeD;
        three->next=NULL;
    }
    return oneD;
}

