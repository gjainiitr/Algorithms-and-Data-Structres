/*
	Problem URL :- https://practice.geeksforgeeks.org/problems/solve-the-sudoku-1587115621/1
*/
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  

bool SolveSudoku(int grid[N][N]);

void printGrid(int grid[N][N]);

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		
		if (SolveSudoku(grid) == true)  
            printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}// } Driver Code Ends


bool isSafe(int grid[N][N], int i, int j, int n) {
    for(int k=0; k<9; k++) {
    	if(grid[i][k]==n || grid[k][j]==n) return false;
	}
//    int temp = 3;
	int subi = i/3, subj = j/3;
//    int subi=i - i%temp, subj=j - j%temp;
    subi = subi * 3;
    subj = subj * 3;
//    cout<<"\n"<<subi<<" "<<subj<<"\n";
     for(int p=subi; p<3+subi; p++) {
        for(int q=subj; q<3+subj; q++) {
            if(grid[p][q]==n) return false;
        }
    }
    return true;
}
bool SolveSudoku(int grid[N][N])  
{ 
    // Your code here
    int i,j;
    for(i=0; i<9; i++) {
        for(j=0; j<9; j++) {
            if(grid[i][j]==0) break;
        }
        if(j!=9) break;
    }
    if(i==9 && j==9) return true;
    for(int n=1; n<=9; n++) {
        if(isSafe(grid,i,j,n)) {
            grid[i][j] = n;
            if(SolveSudoku(grid) == true) return true;
            grid[i][j] = 0;
        }
    }
    return false;
}
void printGrid (int grid[N][N]) 
{
    // Your code here 
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cout<<grid[i][j]<<" ";
        }
        // cout<<endl;
    }
}

