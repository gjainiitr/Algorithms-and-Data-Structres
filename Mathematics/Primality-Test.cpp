// Problem URL :- https://practice.geeksforgeeks.org/problems/primality-test/1


#include<bits/stdc++.h>
using namespace std;

/*This is a function problem.You only need to complete the function given below*/
//User function Template for C++
//You need to complete this function
bool isPrime(int N)
{
   bool prime = 1;
	
	// Check if its prime
	for(int k=2; k<N; k++) {
		if (N%k==0) { // It means divisible by no.s b/w 2 and n-1, i.e. Not prime
			prime = 0;
		}
	}
	return prime;
}


int main()
{
    int T; //testcases
    cin>>T; //input testcases
    while(T--) //while testcase have not been exhausted
    {
        int N;
        cin>>N; //input n
        
        if(isPrime(N)) 
        cout<<"Yes";
        else
            cout<<"No";
            
        cout << endl;
    }
    return 0;
}

