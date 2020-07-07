 // Problem URL :- https://practice.geeksforgeeks.org/problems/minimum-absloute-difference-between-adjacent-elements-in-a-circular-array-1587115620/1
 
 #include<bits/stdc++.h>
 using namespace std;

/*This is a function problem.You only need to complete the function given below*/

// Function to find minimum adjacent difference
// arr[]: input array
// n: size of array
int modulu(int n) {
    if(n>0) return n;
    else return -1*n;
}
int minAdjDiff(int arr[], int n){    
    // Your code here
    // To find minimum adjacent difference
    int minval = modulu(arr[n-1]-arr[0]);
    for(int i=0; i<n-1; i++) {
        // minval = min(modulus(arr[i+1]-arr[i]), minval);
        minval = modulu(arr[i+1]-arr[i])>minval?minval:modulu(arr[i+1]-arr[i]);
    }
    return minval;
}

// Driver code
int main()
{
    int t;
    cin>>t; //Input testcases
    
    while(t--) //While testcases exist
    {
        int n;
        cin>>n; //Input size of array
        
        int arr[n]; //Array of size n
        
        for(int i = 0; i < n; i++)
        {
            cin>>arr[i]; //input elements of array
        }
        
        cout << minAdjDiff(arr, n) << endl;
    }
    return 0;
}
