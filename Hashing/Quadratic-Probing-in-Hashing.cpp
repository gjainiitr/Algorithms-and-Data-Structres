// Problem URL :- https://practice.geeksforgeeks.org/problems/quadratic-probing-in-hashing-1587115621/1

#include <bits/stdc++.h>
using namespace std;

void QuadraticProbing(int hash[],int hashSize,int arr[],int sizeOfArray);

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int hashSize;
	    cin>>hashSize;
	    int hash[hashSize];
	    
	    
	    
	    int  sizeOfArray;
	    cin>>sizeOfArray;
	    int arr[sizeOfArray];
	    
	    for(int i=0;i<sizeOfArray;i++)
	    cin>>arr[i];
	    
	    
	    for(int i=0;i<hashSize;i++)
	    hash[i]=-1;
	    
	    QuadraticProbing( hash, hashSize, arr, sizeOfArray);
	    
	    for(int i=0;i<hashSize;i++)
	    cout<<hash[i]<<" ";
	    
	    cout<<endl;
	    
	    
	}
	return 0;
}// } Driver Code Ends


void QuadraticProbing(int hash[],int hashSize,int arr[],int sizeOfArray)
{
    //Your code here
    int temp,loc,count=0;
    for(int i=0; i<sizeOfArray; i++) {
        loc = arr[i]%hashSize;
        temp = loc;
        if(hash[temp]==-1) {
            hash[temp] = arr[i];
        } else {
            count=0;
            while(hash[temp]!=-1) {
                temp = loc;
                temp = (temp+(count*count))%hashSize;
                count++;
                }
            }
            hash[temp] = arr[i];
        }
    }
