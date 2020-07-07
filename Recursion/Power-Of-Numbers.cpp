// Problem URL :- https://practice.geeksforgeeks.org/problems/power-of-numbers-1587115620/1

#include<bits/stdc++.h>
using namespace std;
# define mod 1000000007


// compute reverse of a number 
long long rev(long long n)
{
    long long rev_num = 0;
     while(n > 0) 
      { 
        rev_num = rev_num*10 + n%10; 
        n = n/10; 
      } 
      return rev_num;
}



long long power(int N,int R);

int main()
{
    int T;
    cin>>T;
    
    while(T--)
    {
        long long N;
        cin>>N;
        
        long long R = 0; 
        
        // reverse the given number n
        R = rev(N);
        long long ans =power(N,R);
        cout << ans<<endl;
    }
}/*This is a function problem.You only need to complete the function given below*/
//You need to complete this fucntion
long long power(int N,int R)
{
   //Your code here
    if(R==1) return N;
    else return((N*power(N,R-1))%1000000007);
}

