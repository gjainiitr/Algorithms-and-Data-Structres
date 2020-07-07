// Problem URL :- https://practice.geeksforgeeks.org/problems/linked-list-insertion-1587115620/1

import java.util.*;
class Node
{
    int data;
    Node next;
    Node(int d) {data = d; next = null; }
}
		
class GfG
{
     /* Drier program to test above functions */
    public static void main(String args[])
    {
         Scanner sc = new Scanner(System.in);
		 int t=sc.nextInt();
		 
		 while(t-->0)
         {
            LList myList = new LList();
			int n = sc.nextInt();
            sc.nextLine();
            for(int i=0;i<n;i++)
            {
                int a1=sc.nextInt();
                int a2=sc.nextInt();
                if(a2==0)
                    myList.insertAtBeginning(a1);
                else
                    myList.insertAtEnd(a1);
            }
			myList.printList();
		}
	}
}

// } Driver Code Ends
/*class Node
    {
        int data;
        Node next;
        Node(int d) {data = d; next = null; }
    }*/
class LList
{
    Node head; 
    
	void insertAtBeginning(int x){
	    Node newHead = new Node(x);
	    newHead.next=head;
	    head=newHead;
	 //   printList();
	}
	
	void insertAtEnd(int x)	{
	    Node temp = head;
	    if(head==null){
	        head=new Node(x);
	    }else{
	    while(temp!=null && temp.next!=null){
	     temp=temp.next;   
	    }
	    Node newTail = new Node(x);
	    temp.next=newTail;
	    newTail.next=null;
	    }
	  //  printList();
	}
	
	void printList()
    {
        Node temp = head;
        while (temp != null)
        {
           System.out.print(temp.data+" ");
           temp = temp.next;
        }  
        System.out.println();
    }
}

