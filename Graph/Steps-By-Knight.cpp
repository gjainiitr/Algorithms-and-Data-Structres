/*
	Problem URL :- https://practice.geeksforgeeks.org/problems/steps-by-knight/0
*/
#include <bits/stdc++.h> 
using namespace std; 
int findSteps(int n, int i, int j, int p, int q) {
    int distance[n][n];
    for(int a=0; a<n; a++) {
        for(int b=0; b<n; b++) {
            distance[a][b] = -1;
        }
    }
    distance[i][j]=0;
    queue<pair<int,int>> que;
    que.push(pair<int,int> (i,j));
    int x_rep[] = {-2,-1,1,2,2,1,-1,-2};
    int y_rep[] = {1,2,2,1,-1,-2,-2,-1};
    while(que.size()>0) {
        pair<int,int> temp = que.front();
        que.pop();
        int x = temp.first;
        int y = temp.second;
        for(int it=0; it<8; it++) {
            int x_curr = x + x_rep[it];
            int y_curr = y + y_rep[it];
            if(x_curr>=0 && x_curr<n && y_curr>=0 && y_curr<n) {
                if(distance[x_curr][y_curr]==-1) {
                    distance[x_curr][y_curr] = 1 + distance[x][y];
                    que.push(pair<int,int> (x_curr,y_curr));
                }
                if(x_curr==p && y_curr==q) return distance[x_curr][y_curr];
            }
        }
    }
    return distance[p][q];
}
int main() 
{   // We will find minimum distance using BFS, its important
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        int i,j,p,q;
        cin>>i>>j;
        cin>>p>>q;
        cout<<findSteps(n,i-1,j-1,p-1,q-1)<<endl;
    }

	return 0;
}   // } Driver Code Ends
