// Problem URL :- https://practice.geeksforgeeks.org/problems/linear-probing-in-hashing-1587115620/1

#include <bits/stdc++.h>
using namespace std;


void linearProbing(int hash[],int hashSize,int arr[],int sizeOfArray);
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
	    
	    linearProbing( hash, hashSize, arr, sizeOfArray);
	    
	    for(int i=0;i<hashSize;i++)
	    cout<<hash[i]<<" ";
	    
	    cout<<endl;
	    
	    
	}
	return 0;
}// } Driver Code Ends
//Complete this function
void linearProbing(int hash[],int hashSize,int arr[],int sizeOfArray)
{
    //Your code here
    int temp,loc;
    bool noPlace = false;
    for(int i=0; i<sizeOfArray; i++) {
        loc = arr[i]%hashSize;
        temp = loc;
        if(hash[temp]==-1) {
            hash[temp] = arr[i];
        } else {
            noPlace = false;
            while(hash[temp]!=-1) {
                temp = (temp+1)%hashSize;
                if(temp==loc) {
                    noPlace = true;
                    break;
                }
            }
            if(!noPlace) hash[temp] = arr[i];
            
        }
    }
}

