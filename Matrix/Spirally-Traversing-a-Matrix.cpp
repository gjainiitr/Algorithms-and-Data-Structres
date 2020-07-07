// Problem URL :- https://practice.geeksforgeeks.org/problems/spirally-traversing-a-matrix-1587115621/1

#include <iostream>
using namespace std;

#define SIZE 30

void spirallyTraverse(int m, int n, int ar[SIZE][SIZE]);

int main() {
	int T = 0;
	
	scanf("%d",&T);
	
	while(T--)
	{
        int m,n;
        scanf("%d",&m);
        scanf("%d",&n);
	    int ar[SIZE][SIZE] = {{0}};
	    int i = 0;
	    int j = 0;
	    int row = 0;
	    int col = 0;
	    
	    for(i=0; i<m; i++)
	    {
	        for(j=0; j<n; j++)
	        {
	            scanf("%d",&ar[i][j]);
	        }
	    }
	    
	    spirallyTraverse(m, n, ar);
	    cout<<endl;
	   
	}
	return 0;
}// } Driver Code Ends
//Complete this function
void spirallyTraverse(int m, int n, int ar[SIZE][SIZE]){
    int ilb=0,jlb=0,iup=m,jup=n;
	while(true) {
		if(ilb==iup || jlb==jup) break;
		for(int i=jlb; i<jup; i++) {
			cout<<ar[ilb][i]<<' ';
		}
		ilb++;
		if(ilb==iup || jlb==jup) break;
		for(int i=ilb; i<iup; i++) {
			cout<<ar[i][jup-1]<<' ';	
		}
		jup--;
		if(ilb==iup || jlb==jup) break;
		for(int i=jup-1; i>=jlb; i--) {
			cout<<ar[iup-1][i]<<' ';
		}
		iup--;
		if(ilb==iup || jlb==jup) break;
		for(int i=iup-1; i>=ilb; i--) {
			cout<<ar[i][jlb]<<' ';
		}
		jlb++;
	}
}

