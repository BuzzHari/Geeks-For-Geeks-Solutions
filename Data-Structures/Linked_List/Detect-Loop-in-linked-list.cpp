// driver code
#include <bits/stdc++.h>
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
        walk = walk->next;// { Driver Code Starts

    tail->next = walk;
}

bool detectLoop(Node* head);

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
        
        if( detectLoop(head) )
            cout<< "True\n";
        else
            cout<< "False\n";
    }
	return 0;
}


// } Driver Code Ends
/*

struct Node
{
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }

*/

// Solved it using Floyd cycle finding algorithm. 
// Which uses two pointer at different speeds to find the loop. 
// For proof, watch this: https://youtu.be/-YiQZi3mLq0  
// https://stackoverflow.com/q/2936213/8212647

bool detectLoop(Node* head)
{
    // your code here

    if (!head)
        return 0;
    


    Node *slowptr = head, *fastptr = head;

    while(fastptr->next) {
        
        fastptr = fastptr->next;
        if(fastptr->next){
            fastptr = fastptr->next;
            slowptr = slowptr->next;

            if (slowptr == fastptr)
                return 1;
        }
    }
    return 0;
}

