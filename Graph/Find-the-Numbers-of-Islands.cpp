/*
	Problem URL :- https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1
*/
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int findIslands(vector<int> A[], int N, int M);

int main() {

    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        vector<int> A[N];
        for (int i = 0; i < N; i++) {
            vector<int> temp(M);
            A[i] = temp;
            for (int j = 0; j < M; j++) {
                cin >> A[i][j];
            }
        }
        cout << findIslands(A, N, M) << endl;
    }
    return 0;
}// } Driver Code Ends


/*you are required to complete this method*/

/*  Function to find number of islands in the given graph
*   A[]: input array
*   N, M: Row and column of given matrix
*/
void checkForIslands(vector<int> A[], int N, int M, int i, int j, vector<bool> visited[]) {
    /*
        for any element :-
            Check only its right, down and right-down
    */
    if(i<0 || j<0) return;
    if(i>=N || j>=M) return;
    // if(A[i][j]==0) return;
    visited[i][j] = 1;
    // bool shouldIncrease = true;
    for(int p=i-1; p<=i+1; p++) {
        for(int q=j-1; q<=j+1; q++) {
            if(p<0 || p>=N) continue;
            if(q<0 || q>=M) continue;
            if(p==i && q==j) continue;
            // if(A[p][q]==0) visited[p][q]=true;
            // if(A[p][q]==true && visited[p][q]==true) shouldIncrease=false;
            if(A[p][q]==1 && visited[p][q]==false) {
                checkForIslands(A,N,M,p,q,visited);
            } 
        }
    }
    // if(shouldIncrease==true) res+=1;
}
int findIslands(vector<int> A[], int N, int M) { // N x M matrix
    int res=0;
    // Naive solution :- An element is counted as an island if
/*
    increase the count iff :-
    1. Its not visited yet
    2. None of its closest 8 which has land is visited yet
    
*/  
    vector<bool> visited[N];
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) visited[i].push_back(0);
    }

    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(A[i][j]==0) visited[i][j]=1;
            if(!visited[i][j] && A[i][j]==1) {
                res+=1;
                checkForIslands(A, N, M, i, j, visited);
            }
        }
    }
    // cout<<"\n#################################\n";
    // for(int i=0; i<N; i++) {
    //     for(int j=0; j<M; j++) {
    //         cout<<visited[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<"#################################\n";    
    
    
    return res;
}
