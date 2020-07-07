// Problem URL :- https://practice.geeksforgeeks.org/problems/possible-words-from-phone-digits-1587115620/1

#include <bits/stdc++.h>
#include <string>

using namespace std;

void possibleWords(int a[],int n);


int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	  possibleWords(a,N);
	   cout << endl;
	}
	
	return 0;
}// } Driver Code Ends
//Complete this function
void phoneDig(vector<char> keypad[], int size[], int currIndex, int endIndex, int a[],string curr) {
    if(currIndex==endIndex) {
        cout<<curr<<' ';
        return;
    }
    int button = a[currIndex]-2;
    int len = size[button];
    for(int i=0; i<len; i++) {
        curr += keypad[button][i];
        phoneDig(keypad,size,currIndex+1,endIndex,a,curr);
        curr.erase(curr.size()-1);
    }
}

void possibleWords(int a[],int N)
{
    //Your code here
    vector<char> keypad[8] = {
        {'a','b','c'},
        {'d','e','f'},
        {'g','h','i'},
        {'j','k','l'},
        {'m','n','o'},
        {'p','q','r','s'},
        {'t','u','v'},
        {'w','x','y','z'}
    };
    int size[8]={3,3,3,3,3,4,3,4};
    phoneDig(keypad,size,0,N,a,"");
}
