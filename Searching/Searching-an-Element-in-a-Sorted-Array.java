// Problem URL :- https://practice.geeksforgeeks.org/problems/who-will-win-1587115621/1

import java.io.*;
import java.util.*;
import java.lang.*;

class gfg
{
    
    public static void main(String args[])throws IOException
    {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        
        while(t-- > 0)
        {
            String s[] = read.readLine().trim().split("\\s+");
            
            int n = Integer.parseInt(s[0]);
            int k = Integer.parseInt(s[1]);
            
            int arr[] = new int[n];
            
            String st[] = read.readLine().trim().split("\\s+");
            
            for(int i = 0; i < n; i++)
            {
                arr[i] = Integer.parseInt(st[i]);
            }
            
            SearchElement obj = new SearchElement();
            
            System.out.println(obj.searchInSorted(arr, n, k));
        }
    }
}/*This is a function problem.You only need to complete the function given below*/
class SearchElement{
    static int searchInSorted(int arr[], int n, int x)
    {
        
        // Your code here
        int l=0;
        int r=n-1;
        int mid;
        while(l<r){
            mid=l+(r-l)/2;
            if(arr[mid]==x){return 1;}
            else if(arr[mid]>x){r=mid-1;}
            else if(arr[mid]<x){l=mid+1;}
        }
        if(arr[l]==x){return 1;}
        return -1;
    }
}
