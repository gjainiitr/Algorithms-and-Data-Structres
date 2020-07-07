// Problem URL :- https://practice.geeksforgeeks.org/problems/merge-three-sorted-arrays-1587115620/1

#include<bits/stdc++.h>
using namespace std; 

typedef vector<int> Vector;

void printVector(const Vector& a) 
{ 
    for (auto e : a) { 
        cout << e << " "; 
    }
    cout<<endl;
} 

 // } Driver Code Ends
// Function to merge three sorted arrays
// A, B, and C: input sorted arrays
Vector merge(Vector &a, Vector& b) {
    int m = a.size(), n = b.size();
    int i=0,j=0,k=0;
    Vector c;
    while(i<m && j<n) {
        if(a[i]<=b[j]) {
            c.push_back(a[i]);
            i++;
        } else {
            c.push_back(b[j]);
            j++;
        }
    }
    while(i<m) {
        c.push_back(a[i]);
        i++;
    }
    while(j<n) {
        c.push_back(b[j]);
        j++;
    }
    return c;
}
Vector mergeThree(Vector& A, Vector& B, Vector& C) 
{ 
    //Your code here
    Vector res;
    res = merge(A,B);
    res = merge(res,C);
    return res;
} 


// { Driver Code Starts.

int main() 
{ 


    int t;
    cin>>t;
    while(t--){
    int n,m,o;
    cin>>n>>m>>o;
    Vector A,B,C;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        A.push_back(x);
    }
    
    for(int i=0;i<m;i++){
        int x;
        cin>>x;
        B.push_back(x);
    }
    
    for(int i=0;i<o;i++){
        int x;
        cin>>x;
        C.push_back(x);
    }

  
    printVector(mergeThree(A, B, C)); 
    
    }
   
    return 0; 
} 
  // } Driver Code Ends
