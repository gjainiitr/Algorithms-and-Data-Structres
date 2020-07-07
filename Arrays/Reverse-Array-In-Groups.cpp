// Problem URL :- https://practice.geeksforgeeks.org/problems/reverse-array-in-groups0255/1

#include<bits/stdc++.h>
using namespace std;

/*This is a function problem.You only need to complete the function given below*/
// Function to reverse the array in groups
int min(int a,int b) {
    if(a>b) return b;
    return a;
}
vector<long long> reverseInGroups(vector<long long> mv, int n, int k){
    // Your code here
    int start,end;
    int temp;
    if(k==1) return mv;
    for(int i=0; i<n; i+=k) {
        start = i;
        end = min(i+k-1,n-1);
        while(start<end) {
            // ***************************
            temp = mv[start];
            mv[start] = mv[end];
            mv[end] = temp;
            // ***************************
            start++;end--;
        }
    }
    return mv;
}

int main() {
    
    int t; //Testcases
    cin >> t; //input the number of testcases

    while(t--){ //while testcases exist

        int n;
        cin >> n; //input the size of array
        
        vector<long long> mv; // Declaring a vector mv
        
        int k;
        cin >> k; //input k 

        for(long long i =0;i<n;i++){
            long long x;
            cin >> x; //input element of array

            mv.push_back(x); //push the element into vector
        }
        
        mv = reverseInGroups(mv, n, k);
        
        for(long long i =0;i<n;i++){
            cout << mv[i] << " "; //Just print the vector
        }

        cout << endl;
        
       

    }

}

