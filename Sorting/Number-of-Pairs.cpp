// Problem URL :- https://practice.geeksforgeeks.org/problems/number-of-pairs-1587115620/1

#include<bits/stdc++.h>
using namespace std;

 
 // } Driver Code Ends
 

int result(int x, int Y[], int n, int noOfY[]) {
    if(x==1) return 0;
    
    int* upperBound = upper_bound(Y, Y+n, x);
    int ans = Y+n-upperBound;
    ans += noOfY[1];
    
    if(x==2) ans-= (noOfY[3] + noOfY[4]);
    if(x==3) ans+=noOfY[2];
    return ans;
}
long long countPairs(int X[], int Y[], int m, int n)
{
   //Your code here
   // Upgrade-1 implementation
   long long count=0;

    int noOfY[5]={0};
    for(int i=0; i<n; i++)
        if(Y[i]<5)
            noOfY[Y[i]]++;
    
   sort(Y,Y+n);
   
   for(int i=0; i<m; i++) {
       count += result(X[i], Y, n, noOfY);
   }
   return count;
}
  

// { Driver Code Starts.
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int M,N;
		cin>>M>>N;
		int i,a[M],b[N];
		for(i=0;i<M;i++)
		{
			cin>>a[i];
		}
		for(i=0;i<N;i++)
		{
			cin>>b[i];
		}
		cout<<countPairs(a, b, M, N)<<endl;
	}
}  // } Driver Code Ends
