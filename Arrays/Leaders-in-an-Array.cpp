// Problem URL :- https://practice.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1

// a given number
#include <bits/stdc++.h>
using namespace std;

/*This is a function problem.You only need to complete the function given below*/
// Function to find the leaders in an array of size n
vector<int> leaders(int arr[], int n){
    
    // Your code here
    
    /******************
     * You just need to complete this
     * function and return the vector
     * containing the leaders.
     * ***************/
     
    vector<int> result;
    result.push_back(arr[n-1]);
    int max = arr[n-1],count=0;;
    for(int i=n-2; i>=0; i--) {
        if(arr[i]>=max) {
            result.push_back(arr[i]);
            max = arr[i];
            count++;
        }
    }
    // reverse(result.begin(),result.end());
    int low=0,high=count,temp;
    while(low<high) {
        temp=result[high];
        result[high]=result[low];
        result[low]=temp;
        high--;low++;
    }
    return result;
}

int main()
{
   long long t;
   cin >> t;
   while (t--)
   {
       long long n;
       cin >> n;
        
        int a[n];
        
        for(long long i =0;i<n;i++){
            cin >> a[i];
        }
        
        vector<int> v = leaders(a, n);
        
        for(auto it = v.begin();it!=v.end();it++){
            cout << *it << " ";
        }
        
        cout << endl;

   }
}

