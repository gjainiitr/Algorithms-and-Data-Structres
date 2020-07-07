// Problem URL :- https://practice.geeksforgeeks.org/problems/case-specific-sorting-of-strings4845/1

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

string caseSort(string str, int n){
    
    // your code here
    vector<int> upper_count,lower_count;
    vector<char> upperCase,lowerCase;
    for(int i=0; i<n; i++) {
        if(str[i]<97) {
            upper_count.push_back(i);
            upperCase.push_back(str[i]);
        } else {
            lower_count.push_back(i);
            lowerCase.push_back(str[i]);
        }
    }
    sort(upperCase.begin(),upperCase.end());
    sort(lowerCase.begin(),lowerCase.end());
    
    for(int i=0; i<upper_count.size(); i++) str[upper_count[i]]=upperCase[i];
    for(int i=0; i<lower_count.size(); i++) str[lower_count[i]]=lowerCase[i];
    
    return str;
}

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string str;
		cin>>str;
		
		cout<<caseSort (str, n)<<endl;
	}
}  // } Driver Code Ends
