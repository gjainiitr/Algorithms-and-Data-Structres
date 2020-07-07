// Problem URL :- https://practice.geeksforgeeks.org/problems/swap-kth-node-from-beginning-and-kth-node-from-end-in-a-singly-linked-list/1

#include <iostream>

using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

void append(Node** head_ref, Node **tail_ref, int new_data)
{
    Node* newnode = new Node(new_data);
    
    if(*head_ref == NULL)
        *head_ref = newnode;
    else
        (*tail_ref)->next = newnode;
    *tail_ref = newnode;
}

Node *swapkthnode(Node* head, int num, int K);

void addressstore(Node **arr, Node* head)
{
    Node* temp = head;
    int i = 0;
    while(temp){
        arr[i] = temp;
        i++;
        temp = temp->next;
    }
}

bool check(Node ** before, Node **after, int num, int K)
{
    if(K > num)
        return 1;
    return (before[K-1] == after[num - K]) && (before[num-K] == after[K-1]);
}

int main()
{
    int T;
    cin>>T;
    while(T--){
        int num, K;
        cin>>num>>K;
        int temp;
        Node* head = NULL;
        Node* tail = NULL;
        for(int i = 0; i<num; i++){
            cin>>temp;
            append(&head, &tail, temp);
        }
        
        Node *before[num];
        addressstore(before, head);
        
        head = swapkthnode(head, num, K);
        
        Node *after[num];
        addressstore(after, head);
        
        if(check(before, after, num, K))
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
}
// } Driver Code Ends
//User function Template for C++

/* Linked List Node structure
   struct Node  {
     int data;
     Node *next;
     Node(int x) {
        data = x;
        next = NULL;
  }
  }
*/

// Should swap Kth node from beginning and Kth
// node from end in list and return new head.
Node *swapkthnode(Node* head, int num, int K)
{
    // Your Code here
    // Step-1 Find the kth node from the beginning and the end
    //Explicitly handle for K=1
    if(K>num) return head;
    Node *beg=head,*end=head;
    if(num%2==0) {
        if(K>num/2) K=num-K+1;
    } else {
        if(K==(num+1)/2) return head;
        if(K>(num+1)/2) K=num-K+1;
    }
    
    if(K==1) {
        Node *second=head->next, *endPre=head;
        while(endPre->next->next!=NULL) endPre=endPre->next; 
        end = endPre->next;
        endPre->next=head;
        head->next=NULL;
        end->next = second;
        return end;
    } else {
        for(int i=1; i<K; i++) beg=beg->next;
        for(int i=1; i<=num-K; i++) end=end->next;
        Node *begPre=head,*endPre=head;
        while(begPre->next!=beg) begPre=begPre->next;
        while(endPre->next!=end) endPre=endPre->next;
        Node *begNext=beg->next, *endNext=end->next;
        begPre->next=end; end->next=begNext;
        endPre->next=beg; beg->next=endNext;
    }
    return head;
}

