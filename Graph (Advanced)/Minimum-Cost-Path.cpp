/*
	Problem URL :- https://practice.geeksforgeeks.org/problems/minimum-cost-path/0
*/

#include<bits/stdc++.h>
using namespace std;
struct node {
    int i,j, dist;
    node(int a,int b,int c=0) {
        i=a;
        j=b;
        dist=c;
    }
};
class myComparator
{
public:
    bool operator() (struct node n1, struct node n2)
    {
        return n1.dist>n2.dist;
    }
};

int minDistance(vector<int> graph[], int n) {
    // int res = 0;
    int distance[n][n];
    bool visited[n][n];
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            visited[i][j] = 0;
            distance[i][j] = INT_MAX;
        }
    }
    // int i=0,j=0;
    distance[0][0]= graph[0][0];
    // visited[i][j]=1;
    int x_dir[4] = {-1,0,1,0};
    int y_dir[4] = {0,1,0,-1};
    priority_queue<node, vector<node>, myComparator> pq; 
    pq.push(node(0,0,graph[0][0]));
    while(!pq.empty()) {
        node temp = pq.top();
        pq.pop();
        int x = temp.i;
        int y = temp.j;
        if(visited[x][y]==1) continue;
        if(x==n-1 && y==n-1) return temp.dist;
        visited[x][y]=1;
        int dist = temp.dist; // dist to reach x,y from 0,0
        for(int p=0; p<4; p++) {
            int x_rep = x + x_dir[p];
            int y_rep = y + y_dir[p];
            if(x_rep >=0 && y_rep>=0 && x_rep<n && y_rep<n) {
                // step-1 relax
                if(!visited[x_rep][y_rep]) { // i.e. its distance is not finalised yet
                    if(distance[x_rep][y_rep] > dist + graph[x_rep][y_rep]) {
                        distance[x_rep][y_rep] = dist +graph[x_rep][y_rep];
                    }
                    pq.push(node(x_rep,y_rep,distance[x_rep][y_rep]));
                }
                // step-2 if not visited, add to pq
            }
        }
    }
    return distance[n-1][n-1];
}
int main() {
    int t;
    cin>>t;
    for(int cs=0; cs<t; cs++) {
        int n;
        cin>>n;
        vector<int> graph[n];
        int x;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                cin>>x;
                graph[i].push_back(x);
            }
        }
        cout<<minDistance(graph,n)<<endl;
    }
}
