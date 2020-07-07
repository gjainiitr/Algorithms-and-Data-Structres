/*
	Problem URL :- https://practice.geeksforgeeks.org/problems/find-whether-path-exist/0
*/
#include <bits/stdc++.h>
using namespace std;
bool findRoute(vector<int> arr[], int n, int i, int j, int p, int q, vector<bool> visited[]) {
    if(i<0 || j<0 || i>=n || j>=n) return false;
    visited[i][j]=1;
    if(i==p && j==q) return true;
    // for(int a=i-1; a<=i+1; a++) {
    //     for(int b=j-1; b<=j+1; b++) {
    //         if(a<0 || a>=n) continue;
    //         if(b<0 || b>=n) continue;
    //         if(a==i && b==j) continue;
            
    //         if(arr[a][b]==3 && visited[a][b]==false) {
    //             if(findRoute(arr,n,a,b,p,q,visited)==true) return true;
    //         }
    //     }
    // }
    if(i-1>=0) { // top
        if(arr[i-1][j]==2) return true;
        if(!visited[i-1][j] && arr[i-1][j]==3) {
            if(findRoute(arr,n,i-1,j,p,q,visited)==true) return true;
        }
    }
    if(i+1<n) { // bottom
        if(arr[i+1][j]==2) return true;
        if(!visited[i+1][j] && arr[i+1][j]==3) {
            if(findRoute(arr,n,i+1,j,p,q,visited)==true) return true;
        }
    }
    if(j-1>=0) { // left
        if(arr[i][j-1]==2) return true;
        if(!visited[i][j-1] && arr[i][j-1]==3) {
            if(findRoute(arr,n,i,j-1,p,q,visited)==true) return true;
        }
    }
    if(j+1<n) { // right
        if(arr[i][j+1]==2) return true;
        if(!visited[i][j+1] && arr[i][j+1]==3) {
            if(findRoute(arr,n,i,j+1,p,q,visited)==true) return true;
        }
    }
    return false;
}
bool pathExist(vector<int> arr[], int n) {
    int i,j,p,q;
    // identify source and destination
    for(int a=0; a<n; a++) {
        for(int b=0; b<n; b++) {
            if(arr[a][b]==1) {
                i=a;
                j=b;
            }
            if(arr[a][b]==2) {
                p=a;
                q=b;
            }
        }
    }
    // cout<<"#####################"<<endl;
    // cout<<i<<" "<<j<<endl;
    // cout<<p<<" "<<q<<endl;
    // cout<<"#####################"<<endl;
    vector<bool> visited[n];
    for(int a=0; a<n; a++) {
        for(int b=0; b<n; b++) {
            visited[a].push_back(0);
        }
    }
    return findRoute(arr,n,i,j,p,q,visited);
}
int main() {
	//code
	int t;
	cin>>t;
	for(int cs=0; cs<t; cs++) {
	    int n;
	    cin>>n;
	    vector<int> arr[n];
	    int x;
	    for(int i=0; i<n; i++) {
	        for(int j=0; j<n; j++) {
	            cin>>x;
	            arr[i].push_back(x);
	        }
	    }
	    cout<<pathExist(arr,n)<<endl;
	}
	return 0;
}
