
// Problem URL :- https://practice.geeksforgeeks.org/problems/numbers-containing-1-2-and-3/0

#include<bits/stdc++.h>
using namespace std;
void num123only(int arr[], int n) {
   int temp, cont;
   sort(arr, arr+n);
   bool notAnswer = false,isEmpty = true;
   unordered_set <int> s;
   for(int i=0; i<n; i++) {
       notAnswer = false;
       temp = arr[i];
       while(temp>0) {
           if((temp%10!=1)&&(temp%10!=2)&&(temp%10!=3)) {
               notAnswer = true;
               break;
           }
           temp = temp/10;
       }
       
       if(!notAnswer) {
           isEmpty = false;
           cout<<arr[i]<<' ';
       }
       
       
   }
   if(isEmpty) cout<<-1;
    
}


int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	     int arr[n];
	    for(int i=0;i<n;i++)
	        cin>>arr[i];
	    num123only(arr,n);
	    cout<<endl;
	    
	}
	return 0;
}//
