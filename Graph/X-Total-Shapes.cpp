/*
	Problem URL :- https://practice.geeksforgeeks.org/problems/x-total-shapes/0
*/
#include<bits/stdc++.h>
using namespace std;
void checkForX(string arr[], int n, int m, vector<bool> visited[], int i, int j) {
    if(i<0 || j<0 || i>=n || j>=m) return;
    visited[i][j] = 1;
    if(i-1>=0) { //top
        if(arr[i-1][j]=='X' && !visited[i-1][j]) {
            checkForX(arr,n,m,visited,i-1,j);
        }
    }
    if(i+1<n) { // bottom
        if(arr[i+1][j]=='X' && !visited[i+1][j]) checkForX(arr,n,m,visited,i+1,j);
        
    }
    if(j-1>=0) { // left
        if(arr[i][j-1]=='X' && !visited[i][j-1]) checkForX(arr,n,m,visited,i,j-1); 
        
    }// check for not visited
    if(j+1<m) { // right
        if(arr[i][j+1]=='X' && !visited[i][j+1]) checkForX(arr,n,m,visited,i,j+1);
        
    }
}
int xTotalShapes(string arr[], int n, int m) {
    int res=0;
    vector<bool> visited[n];
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            visited[i].push_back(0);
        }
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(arr[i][j]=='O') visited[i][j]=1;
            if(!visited[i][j] && arr[i][j]=='X') {
                checkForX(arr,n,m,visited,i,j);
                res+=1;
            }
        }
    }
    return res;
}
int main() {
    int t;
    cin>>t;
    for(int cs=0; cs<t; cs++) {
        int n,m;
        cin>>n>>m;
        string arr[n];
        for(int i=0; i<n; i++) cin>>arr[i];
        cout<<xTotalShapes(arr,n,m)<<endl;
    }
}
