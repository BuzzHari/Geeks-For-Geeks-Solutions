// { Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};



bool isPalindrome(Node *head);
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
   	cout<<isPalindrome(head)<<endl;
    }
    return 0;
}

// } Driver Code Ends


/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/


/*You are required to complete this method */
bool isPalindrome(Node *head)
{
    //Your code here
    if (!head) 
        return 0;
    
    Node *slowptr, *fastptr;
    slowptr=fastptr=head;

    //Find the mid point.
    vector<int> first_half;
    while(fastptr && fastptr->next) {
        first_half.push_back(slowptr->data);
        fastptr = fastptr->next->next;
        slowptr = slowptr->next;
    }

    // Now slowptr is at mid, move and compare with it the
    // elements in the array. 
    
    if (fastptr && !fastptr->next)
        // Only one middle element, so skip it. 
        slowptr = slowptr->next;
    
    // Comparing from the back of the array. 
    int i = first_half.size() - 1; 
    while(slowptr) {
        if (slowptr->data != first_half[i--])
            return 0;
        slowptr = slowptr->next;
    }

    return 1;
}


