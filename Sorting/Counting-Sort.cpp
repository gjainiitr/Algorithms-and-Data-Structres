// Problem URL :- https://practice.geeksforgeeks.org/problems/counting-sort/1

// C Program for counting sort
#include <stdio.h>
#include <string.h>
#define RANGE 255

// The main function that sort the given string arr[] in
// alphabatical order
void countSort(char arr[]);

// Driver program to test above function
int main()
{
    long int t;
    scanf("%ld",&t);
    while(t--)
    {
        long int n;
        scanf("%ld",&n);
        char arr[n+1];
        scanf("%s",arr);
        countSort(arr);
    printf("%s\n", arr);
    }return 0;
}
// } Driver Code Ends
// The main function that sort the given string arr[] in
// alphabatical order

void countSort(char arr[])
{ // (char)num
    int stringCount[26] = {0}; // a=97
    int n = strlen(arr);
    for(int i=0; i<n; i++) {
        stringCount[arr[i]-97]++;
    }
//    for(int i=1; i<26; i++) stringCount[i] = stringCount[i] + stringCount[i-1];
    int j=0,temp;
	for(int i=0; i<26; i++) {
		if(stringCount[i]>0) {
			while(stringCount[i]>0) {
				arr[j] = (char)(97+i);
				j++;
				stringCount[i]--;
			}
		}
	}

}
