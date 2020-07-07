/*
	Problem URL :- https://practice.geeksforgeeks.org/problems/shortest-common-supersequence/0
*/

#include <iostream>
using namespace std;
int lcs(int x, int y, string s1, string s2){ // dp tabulation
    
    // your code here
    int dp[x+1][y+1];
    for(int i=0; i<=x; i++) dp[i][0]=0;
    for(int i=0; i<=y; i++) dp[0][i]=0;
    for(int i=1; i<=x; i++) {
        for(int j=1; j<=y; j++) {
            if(s1[i-1]==s2[j-1]) {
                dp[i][j] = 1+dp[i-1][j-1];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[x][y];
}
int scss(string s1, string s2) {
    int size1=s1.length(), size2=s2.length();
    int LCS = lcs(size1, size2, s1, s2);
    return size1+size2-LCS;
}
int main() {
	int t;
	cin>>t;
	for(int cs=0; cs<t; cs++) {
	    string s1,s2;
	    cin>>s1;
	    cin>>s2;
	    cout<<scss(s1,s2)<<endl;
	}
	return 0;
}
