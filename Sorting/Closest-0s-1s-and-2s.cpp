// Problem URL :- https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s-1587115621/1

#include<bits/stdc++.h>
using namespace std;

void segragate012(int A[], int N);

int main() {

    int T;
    cin >> T;

    while(T--){
        int N;
        cin >>N;
        int A[N];
        for(int i=0;i<N;i++){
            cin >> A[i];
        }

        segragate012(A, N);

        for(int i=0;i<N;i++){
            cout << A[i]  << " ";
        }

        cout << endl;
        
        
    }

}
// } Driver Code Ends


// Function to segregate 0s, 1s and 2s
// A[]: input array
// N: size of array
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
void segragate012(int A[], int N)
{
    //Your code here
    int low = 0, mid = 0, high = N-1;
    while(mid<=high) {
        if(A[mid]==0) {
            swap(A[mid],A[low]);
            mid++; low++;
        } else if (A[mid]==1) {
            mid++;
        } else {
            swap(A[mid],A[high]);
            high--;
        }
    }
}
