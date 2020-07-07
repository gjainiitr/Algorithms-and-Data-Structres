/*
	Problem URL :- https://practice.geeksforgeeks.org/problems/rotten-oranges/0
*/
#include<bits/stdc++.h>
using namespace std;
int rottenOranges(vector<int> arr[], int r, int c) {
    int ans[r][c];
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            ans[i][j]=-1;
        }
    }
    queue<pair<int,int>> q;
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            if(arr[i][j]==2) {
                ans[i][j]=0;
                q.push(pair<int,int>(i,j));
            }
        }
    }
    int x_dir[] = {-1,0,1,0};
    int y_dir[] = {0,1,0,-1};
    if(q.size()==0) return -1; // necessary but not sufficient
    while(q.size()>0) {
        pair<int,int> temp = q.front();
        q.pop();
        // ans to arr[temp] is obviously not -1;
        int x = temp.first;
        int y = temp.second;
        
        for(int i=0; i<4; i++) {
            int x_curr = x + x_dir[i];
            int y_curr = y + y_dir[i];
            if(x_curr>=0 && x_curr<r && y_curr>=0 && y_curr<c) {
                if(arr[x_curr][y_curr]==0) {
                    ans[x_curr][y_curr]=-2;
                    continue;
                }
                if(ans[x_curr][y_curr] == -1) {
                    ans[x_curr][y_curr] = ans[x][y] + 1;
                    q.push(pair<int,int>(x_curr,y_curr));
                }
            }
        }
    }
    int res=-1;
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            if(arr[i][j]==1 && ans[i][j]<=0) return -1;
            res = max(res,ans[i][j]);
        }
    }
    return res;
}
int main() {
    int t;
    cin>>t;
    for(int cs=0; cs<t; cs++) {
        int r,c;
        cin>>r>>c;
        int x;
        vector<int> arr[r];
        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                cin>>x;
                arr[i].push_back(x);
            }
        }
        cout<<rottenOranges(arr,r,c)<<endl;
    }
}
