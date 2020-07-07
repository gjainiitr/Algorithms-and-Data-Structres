// Problem URL :- https://practice.geeksforgeeks.org/problems/exactly-3-divisors/1


#include <bits/stdc++.h>
using namespace std;

/*This is a function problem.You only need to complete the function given below*/
//User function Template for C++
//Complete this function
bool isPrime(int n) 
{ 
    // Corner case 
    if (n <= 1)  return false; 
  
    // Check from 2 to n-1 
    for (int i=2; i<n; i++) 
        if (n%i == 0) 
            return false; 
  
    return true; 
} 
int exactly3Divisors(int N)
{   int count=0,sr; bool prime;
    for(int i=1; i<=N; i++) {
    //Checks for all values from 1 to N and increments the count
        sr = floor(sqrt(i));
        if(!(sr-sqrt(i))&&isPrime(sr)) count++; 
    }
    return count;
}


int main()
 {
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        cout<<exactly3Divisors(N)<<endl;
    }
	return 0;
}
