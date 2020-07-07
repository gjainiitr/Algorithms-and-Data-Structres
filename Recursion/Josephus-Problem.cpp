// Problem URL :- https://practice.geeksforgeeks.org/problems/josephus-problem/1

#include<bits/stdc++.h>
using namespace std;


int josephus(int n, int k);

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		cout<<josephus(n,k)<<endl;
	}
	return 0;
}/*This is a function problem.You only need to complete the function given below*/
/*You are required to complete this method */
int myJosephus(int n, int k)
{
   //Your code here
   if(n==1) return 0;
   else {
     return  (k + myJosephus(n-1,k))%n;
   }
}
int josephus(int n, int k) {
    return (myJosephus(n,k) + 1);
}

