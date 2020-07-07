// Problem URL :- https://practice.geeksforgeeks.org/problems/quadratic-equation-roots/1

/* C++ program to find roots of a quadratic equation */
#include <bits/stdc++.h>
using namespace std;

/*This is a function problem.You only need to complete the function given below*/
//User function Template for C++
//You need to complete this function
void quadraticRoots(int a,int b, int c)
{
   
   //Your code here
   float r1,r2,p1,p2,D = b*b - 4*a*c;
   if(D<0) {cout<<"Imaginary";}
   else
    {
        p1 = (-1 * b)/(2.0 * a);
        p2 = (sqrt(b*b-4*a*c))/(2.0 * a);
        r1 = p1 + p2;
        r2 = p1 - p2;
        cout<<floor(r1)<<' '<<floor(r2);
    }
   
   // Your don't need to printline
   // It will automatically be 
   // handled by driver code
}


int main() {
	int T; 
	cin>>T; //input number of testcases
	
	while(T--)
	{
	    int a, b, c; 
	    cin>>a>>b>>c; //Input a, b, and c
	    
	    quadraticRoots(a,b,c);
	    cout<<endl;
	    
	}
	return 0;
}
