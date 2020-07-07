// Problem URL :- https://practice.geeksforgeeks.org/problems/stock-buy-and-sell-1587115621/1

// Program to find best buying and selling days

#include <bits/stdc++.h>
using namespace std;
 
// solution structure
struct Interval
{
    int buy;
    int sell;
};



 // } Driver Code Ends
// solution structure
/* struct Interval
 {
     int buy;
     int sell;
 };*/

// This function finds the buy sell schedule for maximum profit
void stockBuySell(int price[], int n)
{
    
    // Your code here
    int count=0,check=0,temp=0;
    for(int i=1;i<n;i++)
        {
            if(price[temp]<price[i] && price[i-1]<price[i])
                {count++;check++;
                    if(i==n-1)
                    cout<<"("<<temp<<" "<<i<<")";
                }
            else
                {
                    if(count>0)
                    {
                        cout<<"("<<temp<<" "<<i-1<<") ";
                    }
                        temp=i;count=0;
                
                }
        }
    if(check==0)
    cout<<"No Profit";
}

// { Driver Code Starts.
 
// Driver program to test above functions
int main()
{   
    
    int price[10000],n,i,T;
    
    scanf("%d",&T);
    
    while(T--){
        
    scanf("%d",&n);
    
    for(i=0;i<n;i++)
      scanf("%d",&price[i]);
    // fucntion call
    stockBuySell(price, n);
    cout<<endl;
    }
    return 0;
}  // } Driver Code Ends
