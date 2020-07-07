// Problem URL :- https://practice.geeksforgeeks.org/problems/the-modified-string-1587115621/1

#include<bits/stdc++.h>
#define br char xx; cin>>xx; cout<<xx<<endl;
#define lli long long int
using namespace std;


 // } Driver Code Ends

int modified (string a){
    // Your code here
    int result=0, count=1, len=a.length();
    for(int i=0; i<len-1; i++) {
        if(a[i+1]==a[i]) {
            count++;
        } else {
            result += (count-1)/2;
            count=1;
        }
    }
    result+=(count-1)/2;
    return result;
}

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    string a;
    while(t--){
        cin>>a;
        cout<<modified(a)<<endl;
    }
    return 0;
}
  // } Driver Code Ends
