/*
	Problem URL :- https://practice.geeksforgeeks.org/problems/merge-k-sorted-arrays/1
*/
#include<bits/stdc++.h>


#define N 105
using namespace std;

int *mergeKArrays(int arr[][N],int k);

void printArray(int arr[], int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    int arr[N][N];
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	int *output = mergeKArrays(arr, k);
	printArray(output, k*k);
	cout<<endl;
}
	return 0;
}// } Driver Code Ends
// your task is tocomplete this function
// function should return an pointer to output array int*
// of size k*k
struct node {
  int data;
  int array;
  int index;
  node(int d, int a, int i) {
      data = d;
      array = a;
      index = i;
  }
};
struct myCmp {
public:
  bool operator()(struct node n1,struct node n2) {
      return (n1.data>n2.data);
  }
};
int *mergeKArrays(int arr[][N], int k)
{
    int *res = new int[k*k];
    priority_queue<node, vector<node>, myCmp> pq;
    int i=0;
    
    for(int i=0; i<k; i++) {
        pq.push(node(arr[i][0],i,0));
    }
    while(i<k*k) {
        node temp = pq.top();
        pq.pop();
        res[i]=temp.data;
        i++;
        
        if(temp.index==k-1) continue;
        else pq.push(node(arr[temp.array][temp.index+1],temp.array , temp.index+1));
    }
    return res;
}
