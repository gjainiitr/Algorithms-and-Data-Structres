/*
	Problem URL :- https://practice.geeksforgeeks.org/problems/activity-selection-1587115620/1
*/

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


bool myComparator(pair<int, int> p1, pair<int, int> p2) {
    return p1.second<p2.second; // in ascending order of jobs
}

int activitySelection(int start[], int end[], int n){
    // Your code here
    pair<int, int> jobs[n];
    for(int i=0; i<n; i++) {
        jobs[i].first = start[i];
        jobs[i].second = end[i];
    }
    sort(jobs, jobs+n, myComparator);
    int prev = 0;
    int result = 1;
    
    for(int i=1; i<n; i++) {
        if(jobs[prev].second <= jobs[i].first) {
            result++;
            prev = i;
        }
    }
    
    return result;
}


// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int start[n], end[n];
        
        for(int i=0;i<n;i++)
            cin>>start[i];
        for(int i=0;i<n;i++)
            cin>>end[i];
        
        cout << activitySelection(start, end, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends
