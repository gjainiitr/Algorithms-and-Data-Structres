// Problem URL :- https://practice.geeksforgeeks.org/problems/lru-cache/1

import java.io.*;
import java.util.*;
import java.lang.*;

  public class LRUDesign {

    public static void main(String[] args) throws IOException {
        BufferedReader read =
            new BufferedReader(new InputStreamReader(System.in));

        int t = Integer.parseInt(read.readLine());

        while (t-- > 0) {

            int capacity = Integer.parseInt(read.readLine());
            int queries = Integer.parseInt(read.readLine());
            LRUCache cache = new LRUCache(capacity);
            String str[] = read.readLine().trim().split(" ");
            int len = str.length;
            int itr = 0;

            for (int i = 0; (i < queries) && (itr < len); i++) {
                String queryType = str[itr++];
                if (queryType.equals("SET")) {
                    int key = Integer.parseInt(str[itr++]);
                    int value = Integer.parseInt(str[itr++]);
                    cache.set(key, value);
                }
                if (queryType.equals("GET")) {
                    int key = Integer.parseInt(str[itr++]);
                    System.out.print(cache.get(key) + " ");
                }
            }
            System.out.println();
        }
    }
}
// } Driver Code Ends



// design the class in the most optimal way
class Node
{
    int key, value;
    Node next, pre;

    Node(int key, int value)
    {
        this.key = key;
        this.value = value;
        next = pre = null;
    }
}

class LRUCache
{
    private static Map<Integer, Node> hsMap;
    private static int capacity, count;
    private static Node head, tail;

public LRUCache(int capacity) 
    { 
        this.capacity = capacity; 
        hsMap = new HashMap<>(); 
        head = new Node(0, 0); 
        tail = new Node(0, 0); 
        head.next = tail; 
        tail.pre = head; 
        head.pre = null; 
        tail.next = null; 
        count = 0; 
    } 
  
    public void deleteNode(Node node) 
    { 
        node.pre.next = node.next; 
        node.next.pre = node.pre; 
    } 
  
    public void addToHead(Node node) 
    { 
        node.next = head.next; 
        node.next.pre = node; 
        node.pre = head; 
        head.next = node; 
    } 
  
    // This method works in O(1) 
    public int get(int key) 
    { 
        if (hsMap.get(key) != null) { 
            Node node = hsMap.get(key); 
            int result = node.value; 
            deleteNode(node); 
            addToHead(node); 
            return result; 
        } 
        
        return -1; 
    } 
  
    // This method works in O(1) 
    public void set(int key, int value) 
    { 
        
        if (hsMap.get(key) != null) { 
            Node node = hsMap.get(key); 
            node.value = value; 
            deleteNode(node); 
            addToHead(node); 
        } 
        else { 
            Node node = new Node(key, value); 
            hsMap.put(key, node); 
            if (count < capacity) { 
                count++; 
                addToHead(node); 
            } 
            else { 
                hsMap.remove(tail.pre.key); 
                deleteNode(tail.pre); 
                addToHead(node); 
            } 
        } 
    } 
}

