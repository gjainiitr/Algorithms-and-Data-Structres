// Problem URL :- https://practice.geeksforgeeks.org/problems/delete-middle-element-of-a-stack/1

#include<bits/stdc++.h>
using namespace std;

stack<int> deleteMid(stack<int>s,int sizeOfStack,int current);

int main() {
    int testcases;
    cin>>testcases;
    
    while(testcases--)
    {
        int sizeOfStack;
        cin>>sizeOfStack;
        
        stack<int> myStack;
        
        for(int i=0;i<sizeOfStack;i++)
        {
            int x;
            cin>>x;
            myStack.push(x);
            
            
        }
        if(sizeOfStack==1)
        {
            cout<<myStack.top();
        }
        else
        {
        
            stack<int> modified=deleteMid(myStack,myStack.size(),0);
            
            
            while(!modified.empty())
            {
                cout<<modified.top()<<" ";
                modified.pop();
            }
        }
        cout<<endl;
        
    }   
	return 0;
}// } Driver Code Ends
//User function Template for C++

//You need to complete this function
stack<int> deleteMid(stack<int>s,int sizeOfStack,int current)
{
    //Your code here
    if(sizeOfStack==1) return s;
    int arr[sizeOfStack/2];
    for(int i=0; i<sizeOfStack/2; i++) {
        arr[i] = s.top();
        s.pop();
    }
    s.pop();
    for(int i=sizeOfStack/2 - 1; i>=0; i--) s.push(arr[i]);
    return s;
}


