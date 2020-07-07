// Problem URL :- https://practice.geeksforgeeks.org/problems/maximum-occured-integer4602/1

#include<bits/stdc++.h>
using namespace std;

int arr[1000000];

/*This is a function problem.You only need to complete the function given below*/
// L and R are input array
// maxx : maximum in R[]
// n: size of array
// arr[] : declared globally with size equal to maximum in L[] and R[]
int maxOccured(int L[], int R[], int n, int maxx){
    // Your code here
    // Step-1 : For the array, mark all beginnings and end
    int arr[maxx+1] = {0};
    for(int i=0; i<n; i++) {
        arr[L[i]]++;
        arr[R[i]+1]--;
    }
    // Step-2 : Count occurence of each element
    int max = arr[0],point;
    for(int i=1; i<maxx; i++) {
        arr[i] += arr[i-1];
        if(arr[i]>max){
            point = i;
            max = arr[i];
        }
    }
return point;
}

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    int n;
	    cin >> n;
	    int L[n];
	    int R[n];
	    for(int i = 0;i<n;i++){
	        cin >> L[i];
	    }
	    
	    int maxx = 0;
	    for(int i = 0;i<n;i++){
	        
	        cin >> R[i];
	        if(R[i] > maxx){
	            maxx = R[i];
	        }
	    }
	    
	    cout << maxOccured(L, R, n, maxx) << endl;
	}
	
	return 0;
}
