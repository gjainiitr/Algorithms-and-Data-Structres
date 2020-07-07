// Problem URL :- https://practice.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1

//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;
#define ll long long
queue<ll> modifyQueue(queue<ll> q, int k);
int main(){
    ll t;
    cin>>t;
    while(t-->0){
        ll n,k;
        cin>>n>>k;
        queue<ll> q;
        while(n-->0){
            ll a;
            cin>>a;
            q.push(a);
        }
        queue<ll> ans=modifyQueue(q,k);
        while(!ans.empty()){
            int a=ans.front();
            ans.pop();
            cout<<a<<" ";
        }
        cout<<endl;
    }
}// } Driver Code Ends
//User function Template for C++

queue<ll> modifyQueue(queue<ll> q, int k)
{
    //add code here.
    int n = q.size();
    int arr[n];
    for(int i=0; i<n; i++) {
        arr[i] = q.front();
        q.pop();
    }
    for(int i=k-1; i>=0; i--) {
        q.push(arr[i]);
    }
    for(int i=k; i<n; i++) {
        q.push(arr[i]);
    }
    return q;
}
