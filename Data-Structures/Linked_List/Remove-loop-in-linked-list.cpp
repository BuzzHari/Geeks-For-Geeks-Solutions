// { Driver Code Starts
// driver code

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void loopHere(Node* head, Node* tail, int position)
{
    if(position==0) return;
    
    Node* walk = head;
    for(int i=1; i<position; i++)
        walk = walk->next;
    tail->next = walk;
}

bool isLoop(Node* head)
{
    if(!head) return false;
    
    Node* fast = head->next;
    Node* slow = head;
    
    while( fast != slow)
    {
        if( !fast || !fast->next ) return false;
        fast=fast->next->next;
        slow=slow->next;
    }
    
    return true;
}

int length(Node* head)
{
    int ret = 0;
    while(head)
    {
        ret++;
        head = head->next;
    }
    return ret;
}

void removeLoop(Node* head);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, num;
        cin>>n;
        
        Node *head, *tail;
        cin>> num;
        head = tail = new Node(num);
        
        for(int i=0 ; i<n-1 ; i++)
        {
            cin>> num;
            tail->next = new Node(num);
            tail = tail->next;
        }
        
        int pos;
        cin>> pos;
        loopHere(head,tail,pos);
        
        removeLoop(head);
        
        if( isLoop(head) || length(head)!=n )
            cout<<"0\n";
        else
            cout<<"1\n";
    }
	return 0;
}
// } Driver Code Ends


/*
structure of linked list node:

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

*/

// Use slow pointer and fast pointer approach here, find if loop exists, 
// If loop exists find the the start of the loop by keeping slow ptr at the start
// and move the both pointers with same speed. Also keep a track of the previous node
// while moving the fastptr, as this node will be the last node. 
// Once we find the start of loop, the prev node will have the last node, make this node
// point to NULL. Thus breaking the loop. 

// For proof, watch this: https://youtu.be/-YiQZi3mLq0
// https://stackoverflow.com/q/2936213/8212647

void removeLoop(Node* head)
{
    // code here
    // just remove the loop without losing any nodes

    if (!head)
        return;

    Node *fastptr = head, *slowptr = head;
    int flag = 0; 
    while(fastptr->next) {
        fastptr = fastptr->next;
        if (fastptr->next) {
            fastptr = fastptr->next;
            slowptr = slowptr->next;

            if (fastptr == slowptr) {
                flag = 1;
                break;
            }
        }
    }
    
    Node *prev = fastptr;
    if (flag) {
        slowptr = head;
        // Case when the loop starts at the head of the linked list. 
        if (fastptr == head) {
            fastptr = fastptr->next;
            while(fastptr != slowptr) {
                prev = fastptr;
                fastptr = fastptr->next;
            }
        }
        else {
            while(slowptr != fastptr) {
                slowptr = slowptr->next;
                prev = fastptr;
                fastptr = fastptr->next;
            }
        }
        prev->next = NULL;
    }
}
