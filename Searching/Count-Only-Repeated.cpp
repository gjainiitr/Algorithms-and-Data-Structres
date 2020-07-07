// Problem URL :- https://practice.geeksforgeeks.org/problems/count-only-repeated/0

#include<bits/stdc++.h>
using namespace std;
void countRepeated(int arr[], int n) {
    int counter=1, repeatingNum;
    for(int i=0; i<n-1; i++) {
        if(arr[i]==arr[i+1]) {
            counter++;
            repeatingNum = arr[i];
        }
    }
    cout<<repeatingNum<<" "<<counter;
}
int main() {
	//code
	int t;
	cin>>t;
	for(int i=0; i<t; i++) {
	    int n; cin>>n;
	    int arr[n];
	    for(int k=0; k<n; k++) cin>>arr[k];
	    countRepeated(arr,n);
	    cout<<endl;
	}
	return 0;
}
