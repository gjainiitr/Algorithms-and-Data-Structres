/*
	Problem URL :- https://practice.geeksforgeeks.org/problems/rat-maze-with-multiple-jumps-1587115621/1
*/
#include <bits/stdc++.h>

using namespace std;

void print(int n, vector<int> sol[]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << sol[i][j] << " ";
        }
        cout << endl;
    }
}

void solve(int n, vector<int> maze[]);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> maze[n];
        for (int i = 0; i < n; i++) {
            maze[i].assign(n, 0);
            for (int j = 0; j < n; j++) cin >> maze[i][j];
        }

        solve(n, maze);
    }
    return 0;
}
// } Driver Code Ends


bool isSafe(vector<int> maze[], int n, int i, int j) {
    if(i<n && j<n && maze[i][j]>0) return true;
    return false;
}
bool findSol(vector<int> maze[], int n, vector<int> sol[], int i, int j) {
    if(i==n-1 && j==n-1) {
        sol[i][j]=1;
        return true;
    }
    if(isSafe(maze,n,i,j)) {
        int jumps = maze[i][j];
        sol[i][j]=1;
        for(int idx=1; idx<=jumps; idx++) {
            if(findSol(maze,n,sol,i,j+idx)==true) return true;
            if(findSol(maze,n,sol,i+idx,j)==true) return true;
        }
        // for(int idx=1; idx<=jumps; idx++) {
        // }
        sol[i][j]=0;
    }
    return false;
}
void solve(int n, vector<int> maze[]) {
    // write code here
    vector<int> sol[n];
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            sol[i].push_back(0);
            
    if(findSol(maze,n,sol,0,0)==false) {
        cout<<"-1"<<endl;
    } else {
        // printing the solution matrix
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) cout<<sol[i][j]<<" ";
            cout<<endl;
        }    
    }
}
