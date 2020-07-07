/*
	Problem URL :- https://practice.geeksforgeeks.org/problems/ncr-1587115620/1
*/
// { Driver Code Starts
// A Dynamic Programming based solution to compute nCr % p 
#include<bits/stdc++.h> 
using namespace std; 

const int p = 1e9+7;

int nCrModp(int, int);

// Driver program 
int main() 
{ 
  int t, n, r;
  cin >> t;
  
  while(t--){
      cin >> n >> r;
      cout << nCrModp(n, r) << endl;
  }
  
  return 0; 
}
// } Driver Code Ends
// Returns nCr % p 
int nCrModp(int n, int k)
{   
    if(n<k) return 0;
    int C[n + 1][k + 1];
    int i, j;
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= min(i, k); j++) {

            if (j == 0 || j == i)
                C[i][j] = 1;
            else
                C[i][j] = (C[i - 1][j - 1]%p+ C[i - 1][j]%p)%p;
        }
    }
    return C[n][k];
}

