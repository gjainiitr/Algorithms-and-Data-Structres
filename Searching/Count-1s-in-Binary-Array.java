// Problem URL :- https://practice.geeksforgeeks.org/problems/count-1s-in-binary-array-1587115620/1


import java.io.*;
import java.util.*;
import java.lang.*;

class Arrays {
    
    static int arr[] = new int[5000001];
    
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int t = sc.nextInt();
		
		while(t-- > 0){
		   
		    int n = sc.nextInt();
		    
		    for(int i = 0;i<n;i++){
		        arr[i] = sc.nextInt();
		    }
		    
		    Ones obj = new Ones();
		    System.out.println(obj.countOnes(n));
		    
		    
		}
		
	}
}/*This is a function problem.You only need to complete the function given below*/
//User function Template for Java
class Ones{
    
    // Object of Arrays class to access array declared in Arrays class
    static Arrays obj = new Arrays();
    
    // Function to count number of ones in the binary array
    // n: size of array
    public static int countOnes(int n){
        
        // Your code here
        int l=0;
        int r=n-1;
        int mid;
        while(l<=r){
            mid=l+(r-l)/2;
            if(obj.arr[mid]==1){
                if(mid==n-1){return mid+1;}
                else if(obj.arr[mid+1]==1){l=mid+1;}
                else{return mid+1;}
            }
            else if(obj.arr[mid]<1){r=mid-1;}
        }
        return 0;
    }
    
}

