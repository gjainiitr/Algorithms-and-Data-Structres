// Problem URL :- https://practice.geeksforgeeks.org/problems/kth-smallest-element/0

#include<bits/stdc++.h>
using namespace std;
void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
} 
int lomuto(int arr[], int low, int high) { // correct
	// Done with Lomuto Partition
	
	int j = low,pivot = arr[high];
	for(int i=low; i<high; i++) {
		if(arr[i]<=pivot) {
			swap(arr[i],arr[j]);
			j++;
		} 
	}
	swap(arr[j],arr[high]);
	return j;
}
int kthSmallestElement(int arr[], int n, int x) {
	int low = 0, high = n-1;
	int p = lomuto(arr,low,high);
	while(true) {
	    p = lomuto(arr,low,high);
		if (p == x-1) return arr[p];
		else if (p>x-1) high = p-1;
		else low = p+1;
	}
}
int main() {
    int k;
    cin>>k;
    for(int i=0; i<k; i++) {
        int n;
        cin>>n;
        int arr[n],x;
        for(int i=0; i<n; i++) {
            cin>>arr[i];
        }
        cin>>x;
        sort(arr, arr+n);
        cout<<arr[x-1]<<endl;
    }
}
