/*
	Problem URL :- https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1
*/


// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


 // } Driver Code Ends
 bool myComparator(Job j1, Job j2) {
     return j1.profit>j2.profit; // sorts in decreasing order of profit
 }
void printJobScheduling(Job arr[], int n) 
{ 
    // your code here
    sort(arr, arr+n, myComparator);
    int maxDeadline=0;
    for(int i=0; i<n; i++) maxDeadline = max(maxDeadline, arr[i].dead);
    int order[maxDeadline+1];
    for(int i=0; i<=maxDeadline; i++) order[i]=-1;
    for(int i=0; i<n; i++) {
        int j=arr[i].dead;
        while(j>0) {
            if(order[j]==-1) {
                order[j]=arr[i].profit;
                break;
            } else {
                j--;
            }
        }
    }
    int profit=0, count=0;
    for(int i=1; i<=maxDeadline; i++) {
        if(order[i]!=-1) {
            profit+=order[i];
            count++;
        }
    }
    cout<<count<<" "<<profit<<endl;
} 



// { Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    cin >> t;
    
    while(t--){
        int n;
        cin >> n;
        Job arr[n];
        
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        printJobScheduling(arr, n);
    }
	return 0; 
}


  // } Driver Code Ends
