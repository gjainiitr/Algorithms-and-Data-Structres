/*
	Problem URL :- https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1
*/


#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


 // } Driver Code Ends


//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/
bool myComparator(Item i1, Item i2) {
    double ratio1 = (double)i1.value/i1.weight;
    double ratio2 = (double)i2.value/i2.weight;
    return ratio1>ratio2;
}
// function to return fractionalweights
double fractionalKnapsack(int W, Item arr[], int n)
{
    // Your code here
    sort(arr,arr+n, myComparator); // sorted in decreasing order of ratio
    int i=0;
    double value = 0;
    
    while(W>0) {
        if(i==n) break;
        if(arr[i].weight <= W) {
            W -= arr[i].weight;
            value += arr[i].value;
            i++;
        } else {
            double temp = (double)(arr[i].value*W)/(arr[i].weight);
            value += temp;
            break;
        }
    }
    
    return value;
}


// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		cout<<fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends
