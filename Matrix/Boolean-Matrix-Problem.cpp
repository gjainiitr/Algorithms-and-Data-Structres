// Problem URL :- https://practice.geeksforgeeks.org/problems/boolean-matrix-problem-1587115620/1

#include <bits/stdc++.h>
using namespace std;

#define SIZE 1000

void booleanMatrix(int r, int c, int a[SIZE][SIZE]);

int main() {
	
	int t;
    cin >> t;
    
    while(t--){
        int r,c;
    
        cin >> r >> c; //input the number of rows and columns
        
        int a[SIZE][SIZE]; 
        
        for(int i =0;i<r;i++){
            for(int j =0;j<c;j++){
                cin >> a[i][j]; //input the matrix
            }
        }
        
        booleanMatrix(r, c, a);
            
    }
	
	return 0;
}// } Driver Code Ends
//Complete this function
void booleanMatrix(int r, int c, int a[SIZE][SIZE])
{
    
    //Your  code here
    bool row[r] = {0};
    bool col[c] = {0};
    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++)
            if(a[i][j]==1) {
                row[i]=1;
                col[j]=1;
            }
    for(int i=0; i<r; i++)
        if(row[i]==1)
            for(int j=0; j<c; j++)
                a[i][j]=1;
    for(int j=0; j<c; j++)
        if(col[j]==1)
            for(int i=0; i<r; i++)
                a[i][j]=1;
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++)
            cout<<a[i][j]<<' ';
        cout<<endl;
    }
}
  
