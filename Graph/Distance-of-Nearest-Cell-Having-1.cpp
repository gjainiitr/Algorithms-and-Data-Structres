/*
	Problem URL :- https://practice.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1
*/
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

void print(vector<vector<int>> arr, int row, int col) {

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << arr[i][j] << " ";
        }
    }
    cout << endl;
}


 // } Driver Code Ends


/*  Function to find the distance of nearest cell having 1
*   arr: vector of vectors to represent graph
*   row, col: rows and cols in given matrix
*/

void nearest(vector<vector<int>> arr, int row, int col) {

    // Your code here
    queue<pair<int,int>> q;
    vector<int> temp;
    vector<vector<int>>res;
    for(int i=0; i<col; i++) temp.push_back(-1);
    for(int i=0; i<row; i++) res.push_back(temp);
    
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            if(arr[i][j]==1) {
                res[i][j]=0;
                q.push(pair<int,int>(i,j));
            }
        }
    }
    int x_dir[4] = {0,1,0,-1};
    int y_dir[4] = {-1,0,1,0};
    while(q.size()>0) {
        pair<int,int> curr = q.front();
        q.pop();
        int x = curr.first;
        int y = curr.second;
        for(int i=0; i<4; i++) {
            int x_rep = x + x_dir[i];
            int y_rep = y + y_dir[i];
            if(x_rep>=0 && x_rep<row && y_rep>=0 && y_rep<col) {
                if(res[x_rep][y_rep]==-1) {
                    res[x_rep][y_rep] = res[x][y]+1;
                    q.push(pair<int,int>(x_rep,y_rep));
                }
            }
        }
    }
    print(res,row,col);
}


// { Driver Code Starts.

int main() {

    int tc;
    cin >> tc;
    while (tc--) {
        int row, col;
        cin >> row >> col;

        // Input matrix is represented using vectors of vectors
        vector<vector<int>> graph(row);

        for (int i = 0; i < row; i++) {
            vector<int> temp(col);
            graph[i] = temp;
        }

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                cin >> graph[i][j];
            }
        }

        nearest(graph, row, col);
    }

    return 0;
}  // } Driver Code Ends
