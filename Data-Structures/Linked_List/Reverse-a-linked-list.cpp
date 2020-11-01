// { Driver Code Starts
//Initial Template for C++

// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};


/* Function to get the middle of the linked list*/
struct Node *reverseList(struct Node *head);

void printList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
       printf("%d ", temp->data);
       temp  = temp->next;
    }
}

/* Driver program to test above function*/
int main()
{
    int T,n,l,firstdata;
    cin>>T;

    while(T--)
    {
        struct Node *head = NULL,  *tail = NULL;

        cin>>n;
        
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        
        for (int i=1; i<n; i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
        
        head = reverseList(head);
        
        printList(head);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


/* Linked List Node structure:

struct Node
{
    int data;
    struct Node *next;
}

*/

// What we have: 1 -> 2 -> 3 -> NULL
// What we want: NULL <- 1 <- 2 <- 3, with '3' has our head.
//
// The idea is to keep 3 pointers, one to keep track of prev, one for curr, and one for next.
//
// Initialize prev to NULL, and curr to head.
// Store the next node of curr in next. 
// break the next link of curr and point it to the previous node. 
// and then update the curr with next and repeat till curr becomens null. 
//
// Return prev as new head. 
//

// Should reverse list and return new head.
struct Node* reverseList(struct Node *head)
{
    // code here
    // return head of reversed list

    if (!head)
        return NULL;

    Node *prev, *curr, *next;
    
    prev = NULL;
    curr = head;
    next = head->next;

    while(curr) {

        next = curr->next;
        curr->next = prev;
        prev = curr;

        curr = next;
    }
    
    return prev; 
}

