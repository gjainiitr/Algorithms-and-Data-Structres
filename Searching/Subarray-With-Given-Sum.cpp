// Problem URL :- https://practice.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/1




 // } Driver Code Ends
// Function to find the subarray with given sum k
// arr: input array
// n: size of array
void subarraySum(int arr[], int n, int s){
    // Your code here
    // end does not act as an inclusive part of the counter. This is because
    // we cannot directly add arr[1] at the beginning, as there might be a 
    // chance of n=1. Alternately, we can include end and put end=0 at starting
    int start=0,end=0, sum=arr[0];
    while(end<n) {
        if(sum<s) {
            end++;
            sum+=arr[end];
        } else if(sum==s) {
            cout<<(start+1)<<" "<<(end+1);
            return;
        } else {
            sum-=arr[start];
            start++;
        }
    }
    if(sum!=s) cout<<-1;
}

// { Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        int arr[n];
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        subarraySum(arr, n, s);
        cout<<endl;
        
    }
	return 0;
}  // } Driver Code Ends
