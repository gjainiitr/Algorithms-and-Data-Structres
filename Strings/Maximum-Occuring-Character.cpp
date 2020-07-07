//  Problem URL :- https://practice.geeksforgeeks.org/problems/maximum-occuring-character-1587115620/1

#include<bits/stdc++.h>
using namespace std;

char getMaxOccuringChar(char*);

int main()
{
   
    char str[100];
    int t;
    scanf("%d",&t);
    while(t--)
    {
    	scanf("%s",str);
    cout<< getMaxOccuringChar(str)<<endl;
    }
}// } Driver Code Ends
// Function to get maximum occuring 
// character in given string str
char getMaxOccuringChar(char* str)
{
    // Your code here
    int stringlen = strlen(str);
    // cout<<stringlen;
    int count[256]={0};
    int quant = 0;
    char result;
    for(int i=0; i<stringlen; i++) count[str[i]]++;
    for(int i=0; i<stringlen; i++) {
        if(count[str[i]]>quant) {
            quant = count[str[i]];
            result = str[i];
        } else if (count[str[i]]==quant) {
            if(str[i]<result) result = str[i];
        }
    }
    return result;
}

